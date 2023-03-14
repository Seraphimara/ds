typedef int data_t;
typedef struct node {
	data_t data;
	struct node *next;
}listnode, *linklist;

typedef struct {
	linklist front;
	linklist rear;
}*linkqueue;

linkqueue queue_create();
int enqueue(linkqueue L,data_t data);
data_t dequeue(linkqueue L);
int queue_empty(linkqueue L);
int queue_free(linkqueue L);
