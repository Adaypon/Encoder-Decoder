/*
 * Polikarpov Mihail KMBO-02-20
 */

#include "encrypt.h"

void mutableEncryptCaesar(char* str, const int key) {
	size_t i;
	const size_t len = strlen(str);
	const int ENG_SIZE = 26;
	const int key_edited = key % ENG_SIZE;
	bool upper_flag = false;
	
	for (i = 0; i < len; i++) {
		if (isalpha(str[i])) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				str[i] += 'a' - 'A';
				upper_flag = true;
			}
			
			if (str[i] + key_edited > 'z') {
				str[i] -= ('z' - 'a') + 1;
			}
			if (str[i] + key_edited < 'a') {
				str[i] += ('z' - 'a') + 1;
			}
			
			str[i] += key_edited;
			if (upper_flag) {
				str[i] -= 'a' - 'A';
				upper_flag = false;
			}
		}
	}
}

char* immutableEncryptCaesar(const char* str, const int key) {
	size_t i;
	const size_t len = strlen(str);
	const size_t size = len + 1;
	const int ENG_SIZE = 26;
	const int key_edited = key % ENG_SIZE;
	bool upper_flag = false;
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableEncryptCesar: No memory\n");
		exit(1);
	}
	strcpy(res, str);
	
	for (i = 0; i < len; i++) {
		if (res[i] >= 'A' && res[i] <= 'Z') {
			res[i] += 'a' - 'A';
			upper_flag = true;
		}
		
		if (res[i] + key_edited > 'z') {
			res[i] -= ('z' - 'a') + 1;
		}
		if (res[i] + key_edited < 'a') {
			res[i] += ('z' - 'a') + 1;
		}
		
		res[i] += key_edited;
		if (upper_flag) {
			res[i] -= 'a' - 'A';
			upper_flag = false;
		}
	}		
	return res;
}


void mutableEncryptXOR(char* str, const char* key) {
	size_t i;
	const size_t len = strlen(str);
	const size_t key_len = strlen(key);
		
	for (i = 0; i < len; i++) {
		str[i] ^= key[i % key_len];
	}
}

char* immutableEncryptXOR(const char* str, const char* key) {
	size_t i;
	const size_t len = strlen(str);
	const size_t size = len + 1;
	const size_t key_len = strlen(key);
	char* res = (char *) malloc(size * sizeof(char));
	if (res == NULL) {
		printf("immutableEncryptXOR: No memory\n");
		exit(1);
	}

	
	for (i = 0; i < len; i++) {
		res[i] = str[i] ^ key[i % key_len];
	}
	res[len] ='\0';
	return res;
}