#include "linkqueue.h"
#include <stdio.h>

int main() {
	linkqueue lq = queue_create();
	enqueue(lq,3);
	enqueue(lq,4);
	enqueue(lq,6);
	enqueue(lq,7);
	enqueue(lq,8);
	printf("%d\n",dequeue(lq));
	printf("%d\n",dequeue(lq));
	printf("%d\n",queue_empty(lq));
	queue_free(lq);
	return 0;	
}
