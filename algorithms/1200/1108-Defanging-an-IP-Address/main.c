char * defangIPaddr(char * address){
	char *ret;
	int i = 0;
	int j = 0;
	ret = malloc(strlen(address) + 6 + 1);
	while( address[i] != 0 ) {
		if ( address[i] != '.' ) {
			ret[j++] = address[i++];
		} else {
			ret[j++] = '[';
			ret[j++] = '.';
			ret[j++] = ']';
			i++;
		}
	}
	ret[j] = 0;
	return ret;
}

int main()
{
	printf("%s\n", defangIPaddr("1.1.1.1"));
	return 0;
}
