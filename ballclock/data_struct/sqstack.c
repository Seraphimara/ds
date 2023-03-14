#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"
#include <string.h>
sqstack * stack_create(int len) {
	sqstack *p = (sqstack *)malloc(sizeof(sqstack));
	if (NULL == p) {
		printf("malloc failed\n");
		return NULL;
	}
	data_t *s = (data_t *)malloc(sizeof(data_t)*len);
	if (NULL == s) {
		printf("malloc failed\n");
		free(p);
		return NULL;
	}
	p->data = s;
	memset(p->data,0,len*sizeof(data_t));
	p->maxlen = len;
	p->top = -1;
	return p;
}
int stack_push(sqstack *s,data_t data) {
	if (NULL == s) {
		printf("the pointer is null\n");
		return -1;
	}
	if (s->top == s->maxlen-1) {
		printf("stack is full\n");
		return -1;
	}
	s->top++;
	s->data[s->top] = data;
	return 0;
}
int stack_full(sqstack *s) {
	if (NULL == s) {
		printf("the pointer is null\n");
		return -1;
	}
	return s->top == s->maxlen-1 ? 1 : 0;
	
}
int stack_empty(sqstack *s) {
	if (NULL == s) {
		printf("the pointer is null\n");
		return -1;
	}
	return s->top == -1 ? 1 : 0;
}
data_t stack_pop(sqstack *s) {
	if (NULL == s) {
		printf("the pointer is null\n");
		return -1;
	}
	if (s->top == -1) {
		printf("stack is empty\n");
		return -1;
	}
	s->top--;
	return s->data[s->top+1];
}
data_t stack_top(sqstack *s) {
	if (NULL == s) {
		printf("the pointer is null\n");
		return -1;
	}
	if (s->top == -1) {
		printf("stack is empty\n");
		return -1;
	}
	return s->data[s->top];
}
int stack_clear(sqstack *s) {
	if (NULL == s) {
		printf("the pointer is null\n");
		return -1;
	}
	s->top = -1;
	return 0;
}
int stack_free(sqstack *s) {
	if (NULL == s) {
		printf("the pointer is null\n");
		return -1;
	}
	if (s->data != NULL)
		free(s->data);
	free(s);
	return 0;
}
