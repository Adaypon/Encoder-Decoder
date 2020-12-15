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
	int n = 0;
	
	if (argc == 1) {
		printf("Input method of decrypt [-caesar|-xor]: ");
		scanf("%s", method);
		
		ch = getchar();
		printf("Input text: ");
		while ((ch = getchar()) != '\n' && n < TEXT_SZ) {
			text[n] = ch;
			n++;
		}
		text[n] = '\0';
		
		printf("Input key: ");
		scanf("%s", key);
	} else {
		strcpy(method, argv[1]);
		strcpy(text, argv[2]);
		for (n = 3; n < argc-1; n++) {
			strcat(text, " ");
			strcat(text, argv[n]);
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
		char* text_copy = (char *) malloc(sizeof(char) * (strlen(text) + 1));
		strcpy(text_copy, text);
		char* pch = strtok(text_copy, " ");
		while (pch != NULL) {
			if (!isWord(pch)) {
				printf("Invalid caesar text: %s is not a word\n", pch);
				free(text_copy);
				return -2;
			}
			pch = strtok(NULL, " ");
		}
		free(text_copy);
		
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