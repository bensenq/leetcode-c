#include <stdlib.h>
struct record {
	char *longurl;
	unsigned shorturl;
	struct record *next;
};

unsigned long last_number = 1;

struct record *head = NULL;

struct record *find_record_by_long(char *longurl)
{
	struct record *h = head;
	struct record *r = NULL;
	while(h != NULL) {
		if(strcasecmp(longurl, h->longurl) == 0) {
			r = h;
			break;
		}
		h = h->next;
	}
	return r;
}

struct record *find_record_by_short(unsigned shorturl)
{
	struct record *h = head;
	struct record *r = NULL;
	while(h != NULL) {
		if(shorturl == h->shorturl) {
			r = h;
			break;
		}
		h = h->next;
	}
	return r;
}

struct record *new_record(char *longurl)
{
	struct record *h = head;
	struct record *r = malloc(sizeof(struct record));
	if (head == NULL) {
		head = r;
	} else {
		while(h->next != NULL) {
			h = h->next;
		}
		h->next = r;
	}
	r->longurl = longurl;
	r->shorturl = last_number;
	r->next = NULL;
	last_number++;
	return r;
}

/** Encodes a URL to a shortened URL. */
char* encode(char* longUrl) {
	char *shorturl = malloc(50);
	struct record *r;
	r = find_record_by_long(longUrl);
	if (r == NULL) {
		r = new_record(longUrl);
	}
	snprintf(shorturl, 50, "http://tinyurl.com/%06u", r->shorturl);
	return shorturl;
}

/** Decodes a shortened URL to its original URL. */
char* decode(char* shortUrl) {
	struct record *r;
	unsigned shorturl = atoi(shortUrl+strlen("http://tinyurl.com/"));
	r = find_record_by_short(shorturl);
	return r->longurl;
}

// Your functions will be called as such:
// char* s = encode(s);
// decode(s);
int main()
{
	char *s = "https://leetcode.com/problems/design-tinyurl";
	char* shorts = encode(s);
	printf("%s\n", shorts);
	printf("%s\n", decode(shorts));
	return 0;
}
