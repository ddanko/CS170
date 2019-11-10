#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lexer.h"
#include "parser.h"

int main(){
  char token[20];
  startTokens(20);

  printf("Terminate by typing \"@@\" (two @\'s in a row).\n");

  printf("\n");
  printf("scheme> ");

  strcpy(token, getToken()); //get token

  while (strcmp(token, "@@")){
    S_Expression(token , 0);
    printf("scheme> ");
    strcpy(token, getToken()); //get token
  }
}
