/*
 * Polikarpov Mihail KMBO-02-20
 */

#include "encrypt.h"

void mutableEncryptCaesar(char* str, const int key) {
	size_t i;
	const size_t len = strlen(str);
	const static int EngSZ = 26;
	const int keyEdited = key % EngSZ;
	bool upperFlag = false;
	
	for (i = 0; i < len; ++i) {
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
	const size_t size = strlen(str) + 1;
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableEncryptCaesar: malloc err - No memory\n");
		exit(1);
	}
	strcpy(res, str);
	mutableEncryptCaesar(res, key);
	return res;
}

void mutableDecryptCaesar(char* str, const int key) {
	mutableEncryptCaesar(str, -key);
}

char* immutableDecryptCaesar(const char* str, const int key) {
	return immutableEncryptCaesar(str, -key);
}


void mutableEncryptXOR(char* str, const char* key) {
	size_t i;
	const size_t len = strlen(str);
	const size_t keyLen = strlen(key);
	
	for (i = 0; i < len; ++i) {
		str[i] ^= key[i % keyLen];
	}
}

char* immutableEncryptXOR(const char* str, const char* key) {
	const size_t size = strlen(str) + 1;
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableEncryptXOR: malloc err - No memory\n");
		exit(1);
	}
	strcpy(res, str);
	mutableEncryptXOR(res, key);
	return res;
}

void mutableDecryptXOR(char* str, const char* key) {
	mutableEncryptXOR(str, key);
}

char* immutableDecryptXOR(const char* str, const char* key) {
	return immutableEncryptXOR(str, key);
}