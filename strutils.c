/*
 * Polikarpov Mihail KMBO-02-20
 */

#include "strutils.h"

void mutableToUpper(char* str) {
	size_t i;
	const size_t len = strlen(str);
	
	for (i = 0; i < len; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 'a' - 'A';
		}
	}
}

char* immutableToUpper(const char* str) {
	size_t i;
	const size_t len = strlen(str);
	const size_t size = len + 1;
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableToUpper: No memory\n");
		exit(1);
	}
	
	for (i = 0; i < len; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			res[i] = str[i] - ('a' - 'A');
		} else {
			res[i] = str[i];
		}
	}
	res[len] = '\0';
	return res;
}


void mutableToLower(char* str) {
	size_t i;
	const size_t len = strlen(str);
	
	for (i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 'a' - 'A';
		}
	}
}

char* immutableToLower(const char* str) {
	size_t i;
	const size_t len = strlen(str);
	const size_t size = len + 1;
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableToLower: No memory\n");
		exit(1);
	}

	for (i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			res[i] = str[i] + ('a' - 'A');
		} else {
			res[i] = str[i];
		}

	}
	res[len] = '\0';
	return res;
}


void mutableStrip(char* str) {
	size_t i;
	size_t len;
	size_t begin = 0;
	size_t end = strlen(str) - 1;
	
	while (str[begin] == ' ') {
		if (str[begin + 1] == '\0') {
				break;
		}
		begin++;
	}
	
	if (begin == end) { // empty str
		len = 0;
	} else {
		while (str[end] == ' ') {
			end--;
		}
			
		len = end - begin + 1;
		for (i = 0; i < len; i++) {
			str[i] = str[begin + i]; // rewrite src
		}
	}
	str[len] = '\0';
}

char* immutableStrip(const char* str) {
	size_t i = 0, j = 0;
	size_t len;
	size_t begin = 0;
	size_t end = strlen(str) - 1;
		
	while (str[begin] == ' ') {
		if (str[begin + 1] == '\0') {
				break;
		}
		begin++;
	}
	if (begin == end) { // empty str
		len = 0;
	} else {
		while (str[end] == ' ') {
			end--;
		}
		len = end - begin + 1;
	}
	
	char* res = (char *) malloc((len + 1) * sizeof(char));
	if (res == NULL) {
		printf("immutableStrip: malloc err - No memory\n");
		exit(1);
	}
	
	for (j = 0; j < len; j++){
		res[j] = str[begin + i];
		i++;
	}
	res[len] = '\0';
	
	return res;
}


void mutableStripAll(char* str) {
	size_t i = 0, j = 0;
	size_t len = strlen(str);
	
	while (str[i] != '\0') {
		if (str[i] == ' ') {
			for (j = i; j < len-1; j++) {
				str[j] = str[j+1]; // left shift
			}
			str[len-1] = '\0'; // close last symbol
			len--;
			continue;
		}
		i++;
	}
}

char* immutableStripAll(const char* str) {		
	size_t i = 0, j = 0;
	size_t size = 1;
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableStripAll: malloc err - No memory\n");
		exit(1);
	}
	
	while (str[i] == ' ') { // searching for the beginning
		 i++;
	}
	while (str[i] != '\0') {
		if (str[i] == ' ') {
			i++;
			continue;
		}
		res[j] = str[i];
		i++;
		j++;
		if (j == size) {
			size++;
			res = (char *) realloc(res, size * sizeof(char));
			if (res == NULL) {
				printf("immutableStripAll: realloc err - No memory\n");
				exit(1);
			}
		}
	}
	res[j] = '\0';
	return res;
}


void mutableFilter(char* str) {
	size_t i = 0, j = 0;
	size_t len = strlen(str);
	
	while (str[i] != '\0') {
		if (!isalpha(str[i]) && !isdigit(str[i]) && !isspace(str[i])) {
			for (j = i; j < len-1; j++) {
				str[j] = str[j+1]; // left shift
			}
			str[len-1] = '\0'; // close last symbol
			len--;
			continue;
		}
		i++;
	}
}

char* immutableFilter(const char* str) {
	int i = 0, j = 0;
	int size = 1;
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableFilter: malloc err - No memory\n");
		exit(1);
	}

	while (str[i] != '\0') {
		if (!isalpha(str[i]) && !isdigit(str[i]) && !isspace(str[i])) {
			i++;
			continue;
		}
		res[j] = str[i];
		i++;
		j++;
		if (j == size) {
			size++;
			res = (char *) realloc(res, size * sizeof(char));
			if (res == NULL) {
				printf("immutableFilter: realloc err - No memory\n");
				exit(1);
			}
		}
	}
	res[j] = '\0';
	return res;
}


bool isNumber(const char* str) {
	size_t i;
	const size_t len = strlen(str);
	
	for (i = 0; i < len; i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}


bool isWord(const char* str) {
	size_t i;
	const size_t len = strlen(str);
	
	for (i = 0; i < len; i++) {
		if (!isalpha(str[i])) {
			return false;
		}
	}
	return true;
}
