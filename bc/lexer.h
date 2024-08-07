#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

#define ID 1024
#define DEC 1025

extern int gettoken(FILE *source);

void skipspaces(FILE *tape);
int isID(FILE *tape);

#endif
