/*
 * Polikarpov Mihail KMBO-02-20
 */

#include "strutils.h"
#include "encrypt.h"

#define METHOD_SZ 10
#define TEXT_SZ 256
#define KEY_SZ 32

int main(int argc, char** argv) {
	char method[METHOD_SZ];
	char text[TEXT_SZ];
	char key[KEY_SZ];
	char ch;
	size_t i = 0, j = 0;
	
	if (argc == 1) {
		printf("Input method of decrypt [-caesar|-xor]: ");
		scanf("%s", method);
		
		ch = getchar();
		printf("Input text: ");
		while ((ch = getchar()) != '\n' && i < TEXT_SZ-1) {
			text[i] = ch;
			i++;
		}
		text[i] = '\0';
		
		printf("Input key: ");
		scanf("%s", key);
	} else {
		strcpy(method, argv[1]);
		strcpy(text, argv[2]);
		for (j = 3; j < argc-1; j++) {
			strcat(text, " ");
			strcat(text, argv[j]);
		}
		strcpy(key, argv[argc-1]);
	}

	/*
	printf("Method is %s\n", method);
	printf("Text :%s:\n", text);
	printf("Key :%s:\n", key);
	*/
	
	mutableToLower(method);
	
	if (strcmp(method, "-caesar") == 0) {
		if (!isNumber(key)) {
			printf("Invalid caesar offset key: not a number\n");
			return -1;
		}
		
		// check if every substring is a word
		char* textCopy = (char *) malloc(sizeof(char) * (strlen(text) + 1));
		strcpy(textCopy, text);
		char* pch = strtok(textCopy, " ");
		while (pch != NULL) {
			if (!isWord(pch)) {
				printf("Invalid caesar text: %s is not a word\n", pch);
				free(textCopy);
				return -2;
			}
			pch = strtok(NULL, " ");
		}
		free(textCopy);
		
		mutableEncryptCaesar(text, -(atoi(key)));
	} else if (strcmp(method, "-xor") == 0) {
		mutableEncryptXOR(text, key);
	} else {
		printf("Invalid method flag\n");
		return -3;
	}

	printf("Decoded string: %s\n", text);
	
	return 0;
}