#define NULL 0
struct pair {
	int num;
	char domain[100];
	struct pair *next;
};

<<<<<<< HEAD
struct pair *pair_section1_head;
struct pair *pair_section2_head;
struct pair *pair_section3_head;
=======
struct pair **pair_section1_head;
struct pair **pair_section2_head;
struct pair **pair_section3_head;
>>>>>>> 9bcf8c260ed8305d9e77531ac03b771ba6b26632
struct pair *pair_section1_tail;
struct pair *pair_section2_tail;
struct pair *pair_section3_tail;
int pair_section1_count;
int pair_section2_count;
int pair_section3_count;

/* return true if merged */
<<<<<<< HEAD
int pair_insert(struct pair **head, struct pair **tail, int *count, struct pair *pair) {
	int merged = 0;
	struct pair *tmp;
	if ( *head == NULL) {
		*head = pair;
		*tail = pair;
		*count = 1;
		return merged;
	}

	tmp = *head;
	while(tmp != NULL) {
		if (strcmp(tmp->domain, pair->domain) == 0) {
			tmp->num += pair->num;
			merged = 1;
			break;
		}
		tmp = tmp->next;
	}
	if (merged == 0) {
		(*tail)->next = pair;
		*tail = pair;
		*count = *count+1;
=======
int pair_insert(struct pair *head, struct pair *pair) {
	int merged = 0;
	while(head != NULL) {
		if (strcmp(head->domain, pair->domain) == 0) {
			head->num += pair->num;
			merged = 1;
			break;
		}
		head = head->next;
	}
	if (merged == 0) {
		if (head == NULL)
			head = pair;
		else {
			head->next = pair;
			pair->next = NULL;
		}
>>>>>>> 9bcf8c260ed8305d9e77531ac03b771ba6b26632
	}
	return merged;
}

char *split(char *str, int *count) {
	char *num;
	char *space = strchr(str, ' ');
	num = strndup(str, space - str);
	*count = atoi(num);
	free(num);
	return (space + 1);
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** subdomainVisits(char** cpdomains, int cpdomainsSize, int* returnSize) {
	int i;
	char **result;
	int size = 0;
	int num;
	char *domain;
	int count;
	struct pair *tmp;

	pair_section1_tail = NULL;
	pair_section2_tail = NULL;
	pair_section3_tail = NULL;
	pair_section1_head = NULL;
	pair_section2_head = NULL;
	pair_section3_head = NULL;
	pair_section1_count = 0;
	pair_section2_count = 0;
	pair_section3_count = 0;
	for ( i = 0; i < cpdomainsSize; i++) {
		char *subdomain1, *subdomain2, *subdomain3;
		int merged_uplevel;
		domain = split(cpdomains[i], &num);	
<<<<<<< HEAD
		subdomain2 = strchr(domain, '.');
		subdomain1 = strrchr(domain, '.');
=======
		subdomain1 = strchr(domain, '.');
		subdomain2 = strrchr(domain, '.');
>>>>>>> 9bcf8c260ed8305d9e77531ac03b771ba6b26632
		if (subdomain2 == subdomain1) {
			subdomain2 = domain;
			subdomain3 = NULL;
		} else {
			subdomain2 = subdomain2 + 1;
			subdomain3 = domain;
		}
		subdomain1 = subdomain1+1;
		tmp = malloc(sizeof(struct pair));
		tmp->num = num;
		tmp->next = NULL;
		strcpy(tmp->domain, subdomain1);

<<<<<<< HEAD
		merged_uplevel = pair_insert(&pair_section1_head, &pair_section1_tail, 
				&pair_section1_count, tmp);
=======
		merged_uplevel = pair_insert(pair_section1_head, tmp);
		if (merged_uplevel == 0)
			pair_section1_count++;
>>>>>>> 9bcf8c260ed8305d9e77531ac03b771ba6b26632
		
		tmp = malloc(sizeof(struct pair));
		tmp->num = num;
		tmp->next = NULL;
		strcpy(tmp->domain, subdomain2);
		if (merged_uplevel)
<<<<<<< HEAD
			merged_uplevel = pair_insert(&pair_section2_head, &pair_section2_tail, 
					&pair_section2_count, tmp);
		else {
			if (pair_section2_head == NULL) {
				pair_section2_head = pair_section2_tail = tmp;
				pair_section2_count = 1;
			}
			else {
				pair_section2_tail->next = tmp;
				pair_section2_tail = tmp;
				pair_section2_count++;
			}
=======
			merged_uplevel = pair_insert(pair_section2_head, tmp);
		else {
			if (pair_section2_head == NULL)
				pair_section2_head = pair_section2_tail = tmp;
			else {
				pair_section2_tail->next = tmp;
				pair_section2_tail = tmp;
			}
			pair_section2_count++;
>>>>>>> 9bcf8c260ed8305d9e77531ac03b771ba6b26632
		}

		if (subdomain3 != NULL) {
			tmp = malloc(sizeof(struct pair));
			tmp->num = num;
			tmp->next = NULL;
			strcpy(tmp->domain, subdomain3);
			if (merged_uplevel)
<<<<<<< HEAD
				pair_insert(&pair_section3_head, &pair_section3_tail, 
						&pair_section3_count, tmp);
			else {
				if (pair_section3_head == NULL) {
					pair_section3_head = pair_section3_tail = tmp;
					pair_section3_count = 1;
				}
=======
				pair_insert(pair_section3_head, tmp);
			else {
				if (pair_section3_head == NULL)
					pair_section3_head = pair_section3_tail = tmp;
>>>>>>> 9bcf8c260ed8305d9e77531ac03b771ba6b26632
				else {
					pair_section3_tail->next = tmp;
					pair_section3_tail = tmp;
					pair_section3_count++;
				}
			}
<<<<<<< HEAD
=======
			pair_section3_count++;
>>>>>>> 9bcf8c260ed8305d9e77531ac03b771ba6b26632
		}
	}

	count = pair_section1_count + pair_section2_count + pair_section3_count;
	result = malloc(sizeof(char *) * count);
	i = 0;
<<<<<<< HEAD
	pair_section1_tail->next = pair_section2_head;
=======
	pair_section1_tail = pair_section2_head;
>>>>>>> 9bcf8c260ed8305d9e77531ac03b771ba6b26632
	if (pair_section3_head != NULL)
		pair_section2_tail->next = pair_section3_head;
	tmp = pair_section1_head;
	while(tmp != NULL) {
		char *tmpstr = malloc(110);
<<<<<<< HEAD
		struct pair* next;
		sprintf(tmpstr, "%d %s", tmp->num, tmp->domain);
		result[i] = tmpstr;
		i++;
		next = tmp->next;
		free(tmp);
		tmp = next;
	}

=======
		sprintf(tmpstr, "%d %s", tmp->num, tmp->domain);
		result[i] = tmp;
		i++;
		tmp = tmp->next;
		free(tmp);
	}
>>>>>>> 9bcf8c260ed8305d9e77531ac03b771ba6b26632
	*returnSize = count;
	return result;
}

int main(void)
{
<<<<<<< HEAD
//	char *s = "9001 discuss.leetcode.com";
	int size;
	char *s1 = "900 google.mail.com";
	char *s2 = "50 yahoo.com";
	char *s3 = "1 intel.mail.com";
	char *s4 = "5 wiki.org";
	char *s[4] = {s1, s2, s3, s4};
	subdomainVisits(&s, 4, &size);
=======
	char *s = "9001 discuss.leetcode.com";
	int size;
	subdomainVisits(&s, 1, &size);
>>>>>>> 9bcf8c260ed8305d9e77531ac03b771ba6b26632
}
