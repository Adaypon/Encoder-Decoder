/*
 * Polikarpov Mihail KMBO-02-20
 */

#include "encrypt.h"

#define ENG_SZ 26

void mutableEncryptCaesar(char* str, const int key) {
	size_t i;
	const size_t len = strlen(str);
	const int keyEdited = key % ENG_SZ;
	bool upperFlag = false;
	
	for (i = 0; i < len; i++) {
		if (isalpha(str[i])) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				str[i] += 'a' - 'A';
				upperFlag = true;
			}
			
			if (str[i] + keyEdited > 'z') {
				str[i] -= ('z' - 'a') + 1;
			}
			if (str[i] + keyEdited < 'a') {
				str[i] += ('z' - 'a') + 1;
			}
			
			str[i] += keyEdited;
			if (upperFlag) {
				str[i] -= 'a' - 'A';
				upperFlag = false;
			}
		}
	}
}

char* immutableEncryptCaesar(const char* str, const int key) {
	size_t i;
	const size_t len = strlen(str);
	const size_t size = len + 1;
	const int keyEdited = key % ENG_SZ;
	bool upperFlag = false;
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableEncryptCesar: No memory\n");
		exit(1);
	}
	strcpy(res, str);
	
	for (i = 0; i < len; i++) {
		if (res[i] >= 'A' && res[i] <= 'Z') {
			res[i] += 'a' - 'A';
			upperFlag = true;
		}
		
		if (res[i] + keyEdited > 'z') {
			res[i] -= ('z' - 'a') + 1;
		}
		if (res[i] + keyEdited < 'a') {
			res[i] += ('z' - 'a') + 1;
		}
		
		res[i] += keyEdited;
		if (upperFlag) {
			res[i] -= 'a' - 'A';
			upperFlag = false;
		}
	}		
	return res;
}


void mutableEncryptXOR(char* str, const char* key) {
	size_t i;
	const size_t len = strlen(str);
	const size_t keyLen = strlen(key);
		
	for (i = 0; i < len; i++) {
		str[i] ^= key[i % keyLen];
	}
}

char* immutableEncryptXOR(const char* str, const char* key) {
	size_t i;
	const size_t len = strlen(str);
	const size_t size = len + 1;
	const size_t keyLen = strlen(key);
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableEncryptXOR: No memory\n");
		exit(1);
	}

	
	for (i = 0; i < len; i++) {
		res[i] = str[i] ^ key[i % keyLen];
	}
	res[len] = '\0';
	return res;
}