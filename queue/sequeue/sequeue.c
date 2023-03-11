#include <stdio.h>
#include <stdlib.h>
#include "sequeue.h"
#include <string.h>

sequeue * queue_create() {
	sequeue *s = (sequeue *)malloc(sizeof(sequeue));
	if (s == NULL ) {
		printf("malloc failed\n");
		return NULL;
	}
	memset(s->data,0,sizeof(s->data));
	s->rear = s -> front = 0;
	return s;
}
int enqueue(sequeue *s,data_t data) {
	if (s == NULL) {
		printf("s is NULL\n");
		return -1;
	}
	if ((s->rear+1) % N == s->front) {
		printf("s is full\n");
		return -1;
	}
	s->data[s->rear] = data;
	s->rear = (s->rear + 1) % N;
	return 0;
}
data_t dequeue(sequeue *s) {
	if (s == NULL) {
		printf("s is NULL\n");
		return -1;
	}
	if (s->front == s->rear) {
		printf("s is empty\n");
		return -1;
	}
	int tmp = s->data[s->front];
	s->front = (s->front + 1) % N;
	return tmp;
	
}
int queue_empty(sequeue *s) {
	if (s == NULL) {
		printf("s is NULL\n");
		return -1;
	}
	return s->front == s->rear ? 1 : 0;
}
int queue_full(sequeue *s) {
	if (s == NULL) {
		printf("s is NULL\n");
		return -1;
	}
	return (s-> rear + 1) % N == s->front ? 1 : 0;
}
int queue_free(sequeue *s) {
	if (s == NULL) {
		printf("s is NULL\n");
		return -1;
	}
	free(s);
	s = NULL;
	return 0;
	
}
