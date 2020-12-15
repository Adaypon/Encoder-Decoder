#ifndef H_STRUTILS
#define H_STRUTILS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void mutableToUpper(char* str);
char* immutableToUpper(const char* str);

void mutableToLower(char* str);
char* immutableToLower(const char* str);

void mutableStrip(char* str);
char* immutableStrip(const char* str);

void mutableStripAll(char* str);
char* immutableStripAll(const char* str);

void mutableFilter(char* str);
char* immutableFilter(const char* str);

bool isNumber(const char* str);
bool isWord(const char* str);

#endif