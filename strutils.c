/*
 * Polikarpov Mihail KMBO-02-20
 */

#include "strutils.h"

void mutableToUpper(char* str) {
	size_t i;
	const size_t len = strlen(str);
	
	for (i = 0; i < len; ++i) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 'a' - 'A';
		}
	}
}

char* immutableToUpper(const char* str) {
	const size_t size = strlen(str) + 1;
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableToUpper: malloc err - No memory\n");
		exit(1);
	}
	strcpy(res, str);
	mutableToUpper(res);
	return res;
}


void mutableToLower(char* str) {
	size_t i;
	const size_t len = strlen(str);
	
	for (i = 0; i < len; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 'a' - 'A';
		}
	}
}

char* immutableToLower(const char* str) {
	const size_t size = strlen(str) + 1;
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableToLower: malloc err - No memory\n");
		exit(1);
	}
	strcpy(res, str);
	mutableToLower(res);
	return res;
}


void mutableStrip(char* str) {
	size_t i;
	size_t len;
	size_t begin = 0;
	size_t end = 0;
	
	if (strlen(str) == 0) { // empty str
		len = 0;
	} else {
		end = strlen(str) - 1;
		while (str[begin] == ' ') {
			if (str[begin + 1] == '\0') {
					break;
			}
			++begin;
		}
		
		if (begin == end) { // only spaces in str
			len = 0;
		} else {
			while (str[end] == ' ') {
				--end;
			}
			
			len = end - begin + 1;
			for (i = 0; i < len; ++i) {
				str[i] = str[begin + i]; // rewrite src
			}
		}
	}
	str[len] = '\0';
}

char* immutableStrip(const char* str) {
	const size_t size = strlen(str) + 1;
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableStrip: malloc err - No memory\n");
		exit(1);
	}
	strcpy(res, str);
	mutableStrip(res);
	return res;
}


void mutableStripAll(char* str) {
	size_t i = 0, j = 0;
	size_t len = strlen(str);
	
	for (i = 0; i < len; ++i) {
		if (str[i] != ' ') {
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
}

char* immutableStripAll(const char* str) {
	const size_t size = strlen(str) + 1;
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableStripAll: malloc err - No memory\n");
		exit(1);
	}
	strcpy(res, str);
	mutableStripAll(res);
	return res;
}


void mutableFilter(char* str) {
	size_t i = 0, j = 0;
	size_t len = strlen(str);
	
	for (i = 0; i < len; ++i) {
		if (isalpha(str[i]) || isdigit(str[i]) || isspace(str[i])) {
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
}

char* immutableFilter(const char* str) {
	const size_t size = strlen(str) + 1;
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableFilter: malloc err - No memory\n");
		exit(1);
	}
	strcpy(res, str);
	mutableFilter(res);
	return res;
}


bool isNumber(const char* str) {
	size_t i;
	const size_t len = strlen(str);
	
	if (len == 0) {
		return false;
	}
	
	for (i = 0; i < len; ++i) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}


bool isWord(const char* str) {
	size_t i;
	const size_t len = strlen(str);
	
	if (len == 0) {
		return false;
	}
	
	for (i = 0; i < len; ++i) {
		if (!isalpha(str[i])) {
			return false;
		}
	}
	return true;
}
