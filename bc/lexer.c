#include "lexer.h"

#include <ctype.h>
#include <stdio.h>

void skipspaces(FILE *tape) {
  int ch;
  while (isspace(ch = getc(tape)));
  ungetc(ch, tape);
}

// DEC = [1-9][0-9]* | 0
int isDEC(FILE *tape) {
  int ch = getc(tape);

  if (!isdigit(ch)) {
    ungetc(ch, tape);
    return 0;
  }

  if (ch == '0') return DEC;

  while (isdigit(ch = getc(tape)));
  ungetc(ch, tape);
  return DEC;
}

// ID = [A-z a-z][A-z a-z 0-9]*
int isID(FILE *tape) {
  int ch = getc(tape);

  if (!isalpha(ch)) {
    ungetc(ch, tape);
    return 0;
  }

  while (isalnum(ch = getc(tape)));
  ungetc(ch, tape);
  return ID;
}

int gettoken(FILE *source) {
  int token;

  skipspaces(source);

  if (token = isID(source)) return token;
  if (token = isDEC(source)) return token;

  token = getc(source);
  return token;
}
