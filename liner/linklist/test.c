#include "linklist.h"
#include <stdio.h>

int main() {
	linklist H;
	H = list_create();
	list_tail_insert(H,10);
	list_tail_insert(H,9);
	list_tail_insert(H,8);
	list_show(H);
	list_head_insert(H,7);
	list_head_insert(H,6);
	list_head_insert(H,4);
	list_show(H);
	puts("------------");
	linklist H2 = list_get(H,-1);
	printf("%d ",H2->data);
	H2 = list_get(H,1);
	printf("%d ",H2->data);
	puts("------------");
	list_insert(H,99,0);
	list_insert(H,88,2);
	list_show(H);
	list_reverse(H);
	linklist H3 = list_adjmax(H);
	list_show(H);
	printf("%d \n", H3->data);
	puts("--------------");
   	list_delete(H,0);
	list_show(H);
	puts("------");
	list_delete(H,2);
	list_show(H);	
	puts("------");
	list_delete(H,-1);	
	list_delete(H,-2);
	list_free(H);

	linklist L1,L2;
	L1 = list_create();
	L2 = list_create();
	for (int i = 10; i < 20; ++i) {
		list_tail_insert(L1,i);
	}
	list_show(L1);
	for (int j = 30; j < 40; ++j) {
		list_tail_insert(L2,j);
	}
	list_show(L2);
	list_merge(L1, L2);
	list_show(L1);
}
