/****************************************************************
 File: parser.c
 -------------
 This file implements the interface given in parcer.h.

 ***************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parser.h"
#include "lexer.h"

/***************************************
* Creating consCell struct & createCell
***************************************/

struct conscell {
	char *data;
	struct conscell *car;
	struct conscell *cdr;
};
typedef struct conscell* consCell;

static consCell newCell()
{
	consCell conscell = malloc(sizeof(consCell));

	if (conscell == NULL) {
		printf("Out of memory!\n");
		return NULL;
	}

	conscell -> data = NULL;
	conscell -> car = NULL;
	conscell -> cdr = NULL;

	return conscell;
}


consCell S_Expression(char token[], int recr) {
  consCell local = NULL, temp;
  if (strcmp(token, "(") == 0) {
    local = newCell();
    strcpy(token, getToken());
    local -> car = S_Expression(token, recr + 1);
		temp = local;
		while (strcmp(token, ")") != 0) {
			printf("WHILE\n" );
			temp -> cdr = S_Expression(token, recr + 1);
			printf("BEFORE\n");
			temp = temp -> cdr;
			printf("TEMPCDR\n");
			printf("TOKEN: %s\n", token);
		}
		printf("here?\n");
		// Something's going on here
		temp -> cdr = NULL;
		printf("posthere?\n");
  } else {
		local = newCell();
		local -> data = strdup(token);
		char poop;
		poop = *local->data;
		printf("CHAR %c\n", poop);
		printf("%d\n", recr);
		if (recr > 0) {
			printf("uhoh\n");
			// Something's going on here (can't getToken() when ')')
			strcpy(token, getToken());
			printf("DOM\n" );
		}
		printf("DOM2\n");
	}
	printf("PRERETURN\n");
	printf("TOKENPRE: %s\n", token);
	printf("RECR:   %d\n", recr);
	if (recr == 0) {
		printf("RETURN??\n");
		return local;
	}
	printf("POSTIF\n");
}
