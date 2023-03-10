#include "linkstack.h"
#include <stdlib.h>
#include <stdio.h>

linkstack stack_create() {
	linkstack s = (linkstack)malloc(sizeof(stacknode));
	if (NULL == s) {
		printf("malloc failed\n");
		return NULL;
	}
	s->data = 0;
	s->next = NULL;
	return s;
}
int stack_empty(linkstack s) {
	if (NULL == s) {
		printf("the pointer is NULL\n");
		return -1;
	}	
	return s->next == NULL ? 1 : 0;
}
int stack_push(linkstack s,data_t data) {
	if (NULL == s) {
		printf("the pointer is NULL\n");
		return -1;
	}	
	linkstack p = (linkstack)malloc(sizeof(stacknode));
	if (NULL == p) {
		printf("malloc failed\n");
		return -1;
	}
	p->data = data;
	p->next = s->next;
	s->next = p;
	return 0;
	
	
}
data_t stack_top(linkstack s) {
	if (NULL == s) {
		printf("the pointer is NULL\n");
		return -1;
	}	
	if (NULL == s->next) {
		printf("stack is empty\n");
		return -1;
	}
	return s->next->data;
	
}
data_t stack_pop(linkstack s) {
	if (NULL == s) {
		printf("the pointer is NULL\n");
		return -1;
	}	
	if (NULL == s->next) {
		printf("stack is empty\n");
		return -1;
	}
	data_t tmp = s->next->data;
	linkstack p = s->next;
	s->next = s->next->next;
	free(p);
	p = NULL;
	return tmp;
}
int stack_free(linkstack s) {
	if (NULL == s) {
		printf("the pointer is NULL\n");
		return -1;
	}	
	linkstack p = s;
	while(s != NULL) {
		p = s;
		printf("free %d\n",p->data);
		s = s->next;
		free(p);
		p = NULL;
	}
	return 0;
	
}
