
/****************************************************************
 File: List.c
 ----------------
 This file implements the List interface given in List.h.
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "consCell.h"


/****************************************************************
 The queue is implemented as a linked list of nodes, each
 containing an char queue entry and a pointer to the car node.
*/
struct node {
	char data;
	struct node *car;
	struct node *cdr;
};
typedef struct node Node;

/****************************************************************
 The state of the queue is encapsulated in this struct, which
 contains a pointer to the start and current of the queue. The List
 ADT is a pointer to a struct of this type.
*/
struct list {
	Node *start;
	Node *current;
};

/*****************************************************************/
List createList()
{

	List list = malloc(sizeof(List));

	if (list == NULL) {
		printf("Out of memory!\n");
		exit(1);
	}

	list->start = NULL;
	list->current = NULL;

	return list;
}

/*****************************************************************/
char isEmpty (List list)
{
	return (list->start == NULL) && (list->current == NULL);
}

/****************************************************************
 Implementation note: Each delistt both removes the element from
 the queue and deallocates the node. The last call to free()
 deallocates the list struct.
*/
void deleteList(List list)
{

	do {
		delist(list);
	} while (!isEmpty(list));

	free(list);
}

/****************************************************************
 Implementation note: This is a private function for creating
 an list node pointer with given data contents. It's only
 here to make enlist() a little easier to read.
*/
static Node *createNode(char data)
{
	Node *node = malloc(sizeof(Node));

	if (node == NULL) {
		printf("Out of memory!\n");
		exit(1);
	}

	node->data = data;
	node->car = NULL;
	node->cdr = NULL;

	return node;
}

/****************************************************************
 Implementation note: Since an empty queue just consists of a
 NULL start and current, it is necessary to distinguish that as a
 special case. A similar comment holds for delistt.
*/
void enlist(List list, char data)
{
	Node *node = createNode(data);

	if (!isEmpty(list)) {
		if (data == '(') {
			list->current->car = node;
			list->current = list->current->car;
		}
		if (data == ')') {
			/* code --  *temp (?) */
		}
	}
	else {
		list->start = node;
		list->current = node;
	}
}

/*****************************************************************/
char delist(List list)
{
	Node *temp;
	char data;

	if (list->start == NULL) {
		// list is empty
		return 0;
	}
	else {
		temp = list->start;
		list->start = list->start->car;

		if (list->start == NULL) {
			list->current = NULL;
		}

		data = temp->data;
		free(temp);
		return data;
	}
}

/*****************************************************************/
void printQueue (List list)
{
	Node *current;

	if (isEmpty(list)) {
		printf("Attempt to prchar empty list failed.\n");
		return;
	}

	current = list->start;

	printf("%d  ", current->data);
	while (current != list->current) {
		current = current->car;
		printf("%d  ", current->data);
	}
	printf("\n");
}
