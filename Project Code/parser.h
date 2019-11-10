/****************************************************************
 File: parser.h
 ----------------
  ****************************************************************/
#ifndef PARSER
#define PARSER
#include <stdlib.h>

/****************************************************************
 Function: S_Expression ()
 ------------------------------------
 Starts recursive function to output the parse tree.
 */

struct conscell;
typedef struct conscell *consCell;

consCell S_Expression ();

//^^^ changed from void to  consCell

#endif
