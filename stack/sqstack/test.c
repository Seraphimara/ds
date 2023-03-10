#include "sqstack.h"
#include <stdio.h>

int main() {
	sqstack *s = stack_create(2);
	stack_push(s,2);
	stack_push(s,4);
	printf("%d\n",stack_full(s));
	printf("%d\n",stack_top(s));
	printf("%d\n",stack_pop(s));
	printf("%d\n",stack_pop(s));
	printf("%d\n",stack_empty(s));
	stack_clear(s);
	stack_free(s);
}
