#include <stdio.h>

#include "lexer.h"

int main() {
  int ret;

  while (1) {
    ret = gettoken(stdin);

    if (ret == ID)
      printf("ID\n");
    else if (ret == DEC)
      printf("DEC\n");
    else
      printf("%c\n", ret);
  }

  return 0;
}
