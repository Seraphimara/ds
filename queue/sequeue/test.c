#include <stdio.h>
#include "sequeue.h"

int main() {
	sequeue *s;
	s = queue_create();
	enqueue(s,1);
	enqueue(s,2);
	enqueue(s,3);
	printf("%d\n",dequeue(s));
	printf("%d\n",dequeue(s));
	printf("%d\n",queue_empty(s));
	printf("%d\n",queue_full(s));
	queue_free(s);
}

