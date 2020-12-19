#ifndef H_ENCRYPT
#define H_ENCRYPT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void mutableEncryptCaesar(char* str, const int key);
char* immutableEncryptCaesar(const char* str, const int key);

void mutableDecryptCaesar(char* str, const int key);
char* immutableDecryptCaesar(const char* str, const int key);

void mutableEncryptXOR(char* str, const char* key);
char* immutableEncryptXOR(const char* str, const char* key);

void mutableDecryptXOR(char* str, const char* key);
char* immutableDecryptXOR(const char* str, const char* key);

#endif