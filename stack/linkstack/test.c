#include "linkstack.h"
#include <stdio.h>

int main() {
	linkstack s = stack_create();
	stack_push(s,2);
	stack_push(s,3);
	stack_push(s,4);
	stack_push(s,5);
	printf("%d\n",stack_top(s));
	printf("%d\n",stack_pop(s));
	printf("%d\n",stack_empty(s));
	stack_free(s);
}

