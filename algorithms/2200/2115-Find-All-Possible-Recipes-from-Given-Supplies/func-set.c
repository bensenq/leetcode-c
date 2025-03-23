// Hashmap Set by uthash
// Basic data structures
typedef struct {
    char key[100];
    UT_hash_handle hh;
} StringSet;

typedef struct {
    char key[100];
    int index;
    UT_hash_handle hh;
} RecipeNode;

// Core processing function
char** findAllRecipes(char** recipes, int recipesSize, char*** ingredients, 
                     int ingredientsSize, int* ingredientsColSize, 
                     char** supplies, int suppliesSize, int* returnSize) {
    // ========== Phase 1: Initialize data structures ==========
    StringSet* supplySet = NULL;
    StringSet* recipeNameSet = NULL;
    RecipeNode* remainingRecipes = NULL;
    StringSet* confirmedRecipes = NULL;

    // Initialize the supply set
    for(int i=0; i<suppliesSize; ++i){
        StringSet* s = malloc(sizeof(StringSet));
        strcpy(s->key, supplies[i]);
        HASH_ADD_STR(supplySet, key, s);
    }

    // Build the recipe name set (for quick lookup of whether a name is a recipe)
    for(int i=0; i<recipesSize; ++i){
        StringSet* s = malloc(sizeof(StringSet));
        strcpy(s->key, recipes[i]);
        HASH_ADD_STR(recipeNameSet, key, s);
    }

    // ========== Phase 2: Initial filtering ==========
    // Preprocessing: Remove all recipes that contain unavailable ingredients
    RecipeNode *curr, *tmp;
    for(int i=0; i<recipesSize; ++i){
        bool hasInvalid = false;
        // Check all ingredients
        for(int j=0; j<ingredientsColSize[i]; ++j){
            char* ing = ingredients[i][j];
            StringSet* s;
            // Check if the ingredient is in the supply set
            HASH_FIND_STR(supplySet, ing, s);
            if(s) continue;
            // Check if the ingredient is another recipe name
            HASH_FIND_STR(recipeNameSet, ing, s);
            if(!s){
                hasInvalid = true;
                break;
            }
        }
        // Only keep the recipe if all ingredients are valid
        if(!hasInvalid){
            RecipeNode* rn = malloc(sizeof(RecipeNode));
            strcpy(rn->key, recipes[i]);
            rn->index = i;
            HASH_ADD_STR(remainingRecipes, key, rn);
        }
    }

    // ========== Phase 3: Iterative processing ==========
    char** result = malloc(recipesSize * sizeof(char*));
    *returnSize = 0;
    bool hasNew;

    do {
        hasNew = false;
        RecipeNode *rn, *tmp2;

        // Iterate through remaining recipes
        HASH_ITER(hh, remainingRecipes, rn, tmp2){
            bool canCreate = true;
            // Check if all ingredients are available
            for(int j=0; j<ingredientsColSize[rn->index]; ++j){
                char* ing = ingredients[rn->index][j];
                StringSet* s;
                HASH_FIND_STR(supplySet, ing, s);
                if(s) continue;
                HASH_FIND_STR(confirmedRecipes, ing, s);
                if(!s){
                    canCreate = false;
                    break;
                }
            }

            if(canCreate){
                // Add to the result set
                result[*returnSize] = strdup(rn->key);
                (*returnSize)++;

                // Update the confirmed set
                StringSet* s = malloc(sizeof(StringSet));
                strcpy(s->key, rn->key);
                HASH_ADD_STR(confirmedRecipes, key, s);

                // Remove from the remaining set
                HASH_DEL(remainingRecipes, rn);
                free(rn);
                hasNew = true;
            }
        }
    } while(hasNew); // Stop when no new elements are added

    HASH_CLEAR(hh, supplySet);
    HASH_CLEAR(hh, recipeNameSet);
    HASH_CLEAR(hh, remainingRecipes);
    HASH_CLEAR(hh, confirmedRecipes);

    return result;
}