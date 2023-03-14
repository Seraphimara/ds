#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


hash * hash_create() {
	hash *h = (hash *)malloc(sizeof(hash));
	if(h == NULL) {
		printf("malloc failde\n");
		return NULL;
	}
	memset(h,0,sizeof(hash));
	return  h;
}
int hash_insert(hash *h,datatype data) {
	if(h == NULL) {
		printf("h is NULL\n");
		return -1;
	}
	linklist p = (linklist)malloc(sizeof(listnode));
	if(p == NULL) {
		printf("malloc failde\n");
		return -1;
	}
	p->key = data;
	p->next = NULL;
	
	linklist q = &h->data[data%N];
	while(q->next && q->next->key < p->key) {
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
	return 0;
}
linklist hash_search(hash *h,datatype data) {
	linklist p;
	if(h == NULL) {
		printf("h is NULL\n");
		return NULL;
	}
	p = &(h->data[data%N]);
	while(p->next && data != p->next->key) {
		p = p->next;
	}	
	if(p->next == NULL) { 
		printf("can not find it\n");
		return NULL;
	}
	else {
		printf("find it\n");
		return p->next;
	}
}
