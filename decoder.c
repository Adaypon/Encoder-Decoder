/*
 * Polikarpov Mihail KMBO-02-20
 */

#include "strutils.h"
#include "encrypt.h"

int main(int argc, char** argv) {
	const static int MethodSZ = 10;
	const static int TextSZ = 256;
	const static int KeySZ = 32;

	char method[MethodSZ];
	char text[TextSZ];
	char key[KeySZ];
	char ch;
	size_t i = 0, j = 0;
	
	if (argc != 1 && argc < 4) {
		printf("Invalid number of arguments. Please try again\n");
		return -1;
	}
	
	if (argc == 1) {
		printf("Input method of decrypt [-caesar|-xor]: ");
		scanf("%s", method);
		
		ch = getchar();
		printf("Input text: ");
		while ((ch = getchar()) != '\n' && i < TextSZ-1) {
			text[i] = ch;
			++i;
		}
		text[i] = '\0';
		
		printf("Input key: ");
		scanf("%s", key);
	} else {
		strcpy(method, argv[1]);
		strcpy(text, argv[2]);
		for (j = 3; j < argc-1; ++j) {
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
	mutableStrip(text);
	
	if (strcmp(method, "-caesar") == 0) {
		if (!isNumber(key)) {
			printf("Invalid caesar offset key: not a number\n");
			return -2;
		}
		
		// check if every substring is a word
		char* textCopy = (char *) malloc(sizeof(char) * (strlen(text) + 1));
		strcpy(textCopy, text);
		char* pch = strtok(textCopy, " ");
		while (pch != NULL) {
			if (!isWord(pch)) {
				printf("Invalid caesar text: %s is not a word\n", pch);
				free(textCopy);
				return -3;
			}
			pch = strtok(NULL, " ");
		}
		free(textCopy);
		
		mutableDecryptCaesar(text, atoi(key));
	} else if (strcmp(method, "-xor") == 0) {
		mutableDecryptXOR(text, key);
	} else {
		printf("Invalid method flag\n");
		return -4;
	}

	printf("Decoded string: %s\n", text);
	
	return 0;
}