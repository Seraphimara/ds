typedef int data_t;

typedef struct node {
	data_t data;
	struct node *next;
}stacknode,*linkstack;

linkstack stack_create();
int stack_empty();
int stack_push(linkstack,data_t);
data_t stack_top(linkstack);
data_t stack_pop(linkstack);
int stack_free(linkstack);
