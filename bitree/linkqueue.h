#include "bitree.h"
typedef struct node * datatype;
typedef struct node_t {
	datatype data;
	struct node_t *next;
}listnode, *linklist;

typedef struct {
	linklist front;
	linklist rear;
}*linkqueue;

linkqueue queue_create();
int enqueue(linkqueue L,datatype data);
datatype dequeue(linkqueue L);
int queue_empty(linkqueue L);
int queue_free(linkqueue L);
