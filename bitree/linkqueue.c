#include "linkqueue.h"
#include <stdio.h>
#include <stdlib.h>


linkqueue queue_create() {
	linkqueue q = (linkqueue)malloc(sizeof(listnode));
	if (NULL == q) {
		printf("malloc failed \n");
		return NULL;
	}

	linklist p = (linklist)malloc(sizeof(listnode));
	if (NULL == p) {
		printf("malloc failed \n");
		q = NULL;
		return NULL;
	}
	p->data = 0;
	p->next = NULL;
	q->front = p;
	q->rear = p;
	return q;
	
}
int enqueue(linkqueue L,datatype data) {
	if (NULL == L) {
		printf("L is NULL \n ");
		return -1;
	}
	linklist p = (linklist)malloc(sizeof(listnode));
	if (NULL == p) {
		printf("malloc failed \n");
		return -1;
	}
	p->data = data;
	p->next = NULL;
	L->rear->next = p;
	L->rear = p;
	return 0;
}
datatype dequeue(linkqueue L) {
	if (NULL == L) {
		printf("L is NULL \n ");
		return NULL;
	}
	linklist p = L->front;
	L->front = p->next;
	free(p);
	p = NULL;
	return L->front->data;
}
int queue_empty(linkqueue L) {
	if (NULL == L) {
		printf("L is NULL \n ");
		return -1;
	}
	return (L->front == L->rear ? 1 : 0);

}
int queue_free(linkqueue L) {
	if (NULL == L) {
		printf("L is NULL \n ");
		return -1;
	}
	linklist p;
	while (L->front) {
		p = L->front;
		L->front = p->next;
		free(p);
	}
	free(L->front);
	free(L);
	L = NULL;
	return -1;
}

