#include <stdio.h>
#include "sqlist.h"

int main() {
	sqlink l, l2;
	l = list_create();
	if (NULL == l)
		return -1;
	list_insert(l,10,0);
	list_insert(l,20,1);
	list_insert(l,30,2);
	list_insert(l,40,1);
	list_insert(l,50,0);
	list_insert(l,60,2);
	list_show(l);
	list_delete(l,0);
	list_delete(l,2);
	list_show(l);
	l2 = list_create();
	list_insert(l2,57,0);
	list_insert(l2,60,0);
	list_insert(l2,690,0);
	list_show(l2);
	list_merge(l,l2);
	list_show(l);
	list_insert(l,60,0);
	list_insert(l,30,0);
	list_show(l);
	list_purge(l);
	list_show(l);
	list_free(l);
	list_free(l2);
	l = NULL;
	l2 = NULL;
	return 0;
}
