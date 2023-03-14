#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

bitree tree_create() {
	data_t ch;
	scanf("%c",&ch);
	if(ch == '#') {
		return NULL;
	}
	bitree p = (bitree)malloc(sizeof(struct node));
	if(NULL == p) {
		printf("malloc failed\n");
		return NULL;
	}
	p->data = ch;
	p->left = tree_create();
	p->right = tree_create();
	return p;
}
void preorder(bitree t) {
	if(t == NULL) {
		return ;
	}
	printf("%c  ",t->data);
	preorder(t->left);
	preorder(t->right);
}
void inorder(bitree t) {
	if(t == NULL) {
		return ; 
	}
	inorder(t->left);
	printf("%c  ",t->data);
	inorder(t->right);
}
void postorder(bitree t) {
	if(t == NULL) {
		return ;
	}
	postorder(t->left);
	postorder(t->right);
	printf("%c  ",t->data);
}
void layerorder(bitree t) {
	if(NULL == t) {
		printf("t is NULL\n");
		return ;
	}
	linkqueue lq = queue_create();
	if(NULL == lq) {
		printf("malloc failed\n");
		return ;
	}	
	printf("%c  ",t->data);
	enqueue(lq, t);
	while(!queue_empty(lq)) {
		t = dequeue(lq);
		if(t->left) {
			printf("%c  ",t->left->data);
			enqueue(lq,t->left);
		}
		if(t->right) {
			printf("%c  ",t->right->data);
			enqueue(lq,t->right);
		}
	}
}
	
