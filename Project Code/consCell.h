#ifndef UTILS_INTQUEUE
#define UTILS_INTQUEUE


 struct list;
 typedef struct list *List;

 List createList();

 char isEmpty (List queue);

 void enlist(List queue, char data);

 char delist(List queue);

 void deleteList(List queue);

 void printQueue (List queue);

#endif
