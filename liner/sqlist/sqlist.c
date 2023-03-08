#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sqlist.h"
sqlink list_create() {
	sqlink L = (sqlink)malloc(sizeof(sqlist));
	if(NULL==L) {
		printf("malloc failed!\n");
		return L;
	}
	memset(L,0,sizeof(sqlist));
	L->last = -1;
	return L;
}
/**
 * @ret 0-success -1-failed
 * */
int list_clear(sqlink L) {
	if(L==NULL)
		return -1;
	memset(L,0,sizeof(sqlist));
	L->last = -1;
	return 0;
}
/*
 * list_empty:is the list empty?
 * param L: sqlink
 * @ret 1--empty 0--not empty
 * */
int list_empty(sqlink L) {
	if (L->last == -1)
		return 1;
	else
		return 0;
}
int list_length(sqlink L) {
	if (L == NULL)
		return -1;
	return L->last+1;
}
int list_locate(sqlink L,data_t value) {
	if (L==NULL) 
		return -1;
	for (int i = 0; i <= L->last; ++i) {
		if (value == L->data[i]) 
			return i;
	}
	return -1;
}
int list_insert(sqlink L,data_t value,int pos) {
	if (L->last == N-1) {
		printf("list is full!\n");
		return -1;
	}
	if (pos < 0 || pos > L->last+1) {
		printf("invalid para!!!\n");
		return -1;
	}
	
	for (int i = L->last; i >= pos; --i) {
		L->data[i+1] = L->data[i];
	}
	
	L->data[pos] = value;
	L->last ++;	
	return 0;

}
int list_show(sqlink L) {
	if (L==NULL)
		return -1;
	if (L->last == -1) {
		printf("list is empty!!!\n");
	}
	for (int i = 0; i <= L->last; ++i) {
		printf("%d  ", L->data[i]);
	}
	printf("\n");
	return 0;
}
int list_free(sqlink L) {
	if (L == NULL)
		return -1;
	free(L);
	L = NULL;
	return 0;
}
int list_delete(sqlink L,int pos) {
	if (L->last == -1) {
		printf("list is empty!\n");
		return -1;
	}
	if (pos < 0 || pos > L->last) {
		printf("invalid para!!!\n");
		return -1;
	}
	for (int i = pos; i < L->last; ++i) {
		L->data[i] = L->data[i+1];
	}
	L->last --;
	return 0;
}
int list_merge(sqlink L1,sqlink L2) {
	int i = 0;
	int ret = 0;
	while (i <= L2->last) {
		ret = list_locate(L1, L2->data[i]);
		if (ret == -1) {
			if (list_insert(L1, L2->data[i], L1->last+1) == -1)
					return -1;
		}
		++i;
	}
	return 0;
}
int list_purge(sqlink L) {
	if (L == NULL)
		return -1;
	if (L->last == 0)
		return 0;
	int i = 1, j;
	while (i <= L->last) {
		j = i-1;
		while (j >= 0) {
			if (L->data[i] == L->data[j]) {
				list_delete(L, i);
				break;
			}
			else {
				j--;
			}
		}
		if (j < 0)
			i++;
	}
	return 0;
}
