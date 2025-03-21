//uthash library is used to implement a hash table to store the remainders and their indices.

typedef struct {
    long long remainder;   // Remainder
    int index;             // Index where this remainder first appeared
    UT_hash_handle hh;     // Hash handle for uthash
} HashTable;

char* fractionToDecimal(int numerator, int denominator) {
    // Handle negative signs
    int is_negative = (numerator < 0) ^ (denominator < 0);

    // Convert numerator and denominator to long long to avoid overflow
    long long abs_numerator = labs((long long)numerator);
    long long abs_denominator = labs((long long)denominator);

    // Calculate the integer part
    long long integer_part = abs_numerator / abs_denominator;
    long long remainder = abs_numerator % abs_denominator;

    // Special case: If the integer part is 0 and remainder is 0, return "0"
    if (integer_part == 0 && remainder == 0) {
        return strdup("0");
    }

    // Initialize hash table
    HashTable* hash_table = NULL;

    // Store the decimal part
    char decimal_part[10001] = {0};
    int decimal_index = 0;

    // Flags to detect repetition
    int repeat = 0;
    int repeat_start = -1;

    // Start calculating the decimal part
    while (remainder != 0 && !repeat) {
        // Check if this remainder has appeared before
        HashTable* entry;
        HASH_FIND_INT(hash_table, &remainder, entry);

        if (entry) {
            repeat = 1;
            repeat_start = entry->index;
        } else {
            // If the remainder has not appeared, record its index
            entry = (HashTable*)malloc(sizeof(HashTable));
            entry->remainder = remainder;
            entry->index = decimal_index;
            HASH_ADD_INT(hash_table, remainder, entry);

            // Calculate the next digit in the decimal part
            remainder *= 10;
            int digit = remainder / abs_denominator;
            remainder %= abs_denominator;
            decimal_part[decimal_index++] = '0' + digit;
        }
    }

    // Construct the final result
    int total_length = 20 + strlen(decimal_part); // Include space for sign, integer part, decimal point, and parentheses
    char* result = (char*)malloc(total_length + 1); // +1 for null terminator

    // Append the integer part
    int offset = sprintf(result, "%s%lld", is_negative ? "-" : "", integer_part);

    // If there is a decimal part
    if (decimal_index > 0) {
        result[offset++] = '.'; // Add decimal point
        if (repeat) {
            // Copy the non-repeating part
            memcpy(result + offset, decimal_part, repeat_start);
            offset += repeat_start;
            // Insert the left parenthesis
            result[offset++] = '(';
            // Copy the repeating part
            memcpy(result + offset, decimal_part + repeat_start, decimal_index - repeat_start);
            offset += decimal_index - repeat_start;
            // Insert the right parenthesis
            result[offset++] = ')';
        } else {
            // Copy the entire decimal part
            memcpy(result + offset, decimal_part, decimal_index);
            offset += decimal_index;
        }
    }

    result[offset] = '\0'; // Add null terminator

    // Clean up the hash table
    HashTable* current_entry, *tmp;
    HASH_ITER(hh, hash_table, current_entry, tmp) {
        HASH_DEL(hash_table, current_entry);
        free(current_entry);
    }

    return result;
}