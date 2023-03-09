#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

linklist list_create() {
	linklist H = (linklist)malloc(sizeof(listnode));
	if (NULL == H) {
		printf("malloc failed!!\n");
		return H;
	}
	H->data = 0;
	H->next = NULL;
	return H;
}
linklist list_get(linklist H, int pos) {
	if (NULL == H) {
		printf("H is NULL\n");
		return NULL;
	}
	if (pos < -1) {
		printf("invalid pos\n");
		return NULL;
	}
	linklist p = H;
	int i = -1;
	while (i < pos) {
		if (p->next == NULL) {
			printf("invalid pos!\n");
			return NULL;
		}	
		i++;
		p = p->next;
	}
	return p; 
}
int list_tail_insert(linklist H,data_t data) {
	linklist p, q;
	if (NULL == H) {
		printf("H is NULL\n");
		return -1;
	}
	if (NULL == (p = (linklist)malloc(sizeof(listnode)))) {
		printf("malloc failed\n");
		return -1;
	}	
	p->data = data;
	p->next = NULL;
	q = H;
	while (q->next != NULL) {
		q = q->next;
	}
	q->next = p;
	return 0;
}
int list_head_insert(linklist H,data_t data) {
	linklist p, q;
	if (NULL == H) {
		printf("H is NULL\n");
		return -1;
	}
	if (NULL == (p = (linklist)malloc(sizeof(listnode)))) {
		printf("malloc failed\n");
		return -1;
	}	
	p->data = data;
	p->next = H->next;
	H->next = p;
	return 0;
}
int list_insert(linklist h,data_t data,int pos) {
	linklist p,q;
	if (NULL == h) {
		printf("H is NULL\n");
		return -1;
	}
	if (NULL == (p = list_get(h,pos-1))){
		return -1;
	}
	if (NULL == (q = (linklist)malloc(sizeof(listnode)))) {
		printf("malloc failed\n");
		return -1;
	}
	q->next = p->next;
	q->data = data;
	p->next = q;
	return 0;
}
int list_delete(linklist H,int pos) {
	linklist p, q;
	if (NULL == H) {
		printf("H is NULL\n");
		return -1;
	}
	if (pos == -1) {
		printf("invalid pos\n");
		return -1;
	}
	p = list_get(H,pos-1);
	if (NULL == p) {
		printf("invalid pos\n");
		return -1;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	q = NULL;
	return 0;
}


int list_show(linklist H) {
	linklist p;
	if (NULL == H) {
		printf("H is NULL\n");
		return -1;
	}
	p = H;
	while (p->next != NULL) {
		printf("%d  ",p->next->data);
		p = p->next;
	}
	puts("");
	return 0;
}

int list_free(linklist H) {
	if (NULL == H) {
		printf("H is NULL\n");
		return -1;
	}
	linklist p = H;
	while (H != NULL) {
		H = H->next;
		printf("delete %d\n",p->data);
		free(p);
		p = H;
	}
	return 0; 
}
int list_reverse(linklist H) {
	if (NULL == H) {
		printf("H is NULL\n");
		return -1;
	}
	if (H->next == NULL || H->next->next == NULL) {
		return 0;
	}
	linklist p,q;
	p =  H->next->next;
	H->next->next = NULL;
	while (p != NULL) {
		q=p;
		p = p->next;	
		q->next = H->next;
		H->next = q;
	}
	return 0;

}
linklist list_adjmax(linklist H) {
	if (NULL == H) {
		printf("H is NULL\n");
		return NULL;
	}
	if (H->next == NULL || H->next == NULL || H->next->next == NULL) {
		return H;
	}
	linklist p,q,r;
	p = H->next;
	q = p->next;
	r = p;
	int sum = 0, max = 0;
	while (q->next != NULL) {
		sum = p->data+q->data;
		if (sum > max) {
			r = p;
			max = sum;
		}
		p = p->next;
		q = q->next;
	}	
	return p;
}

int list_merge(linklist H1,linklist H2) {
	if (NULL == H1  || NULL == H2) {
		printf("H1 || H2 is NULL\n");
		return -1;
	}
	linklist p,q,r;
	p = H1->next;
	q = H2->next;
	r = H1;
	H1->next = NULL;
	H2->next = NULL;
	while (p && q) {
		if (p->data < q->data) {
			r->next = p;
			r = r->next;
			p = p->next;	
		}else {
			r->next = q;
			r = r->next;
			q = q->next;
		}
	}
	if (p == NULL) {
		r->next = q;
	}else {
		r->next = p;
	}
	return 0;
}
