#ifndef _HASH_
#define _HASH_

#define N 15

typedef int datatype;

typedef struct node {
	datatype key;
	struct node *next;
}listnode,*linklist;

typedef struct {
	listnode data[N];	
}hash;

hash * hash_create();
int hash_insert(hash *h,datatype data);
linklist hash_search(hash *h,datatype data);
#endif



