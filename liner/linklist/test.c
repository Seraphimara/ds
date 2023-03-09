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
   	list_delete(H,0);
	list_show(H);
	puts("------");
	list_delete(H,2);
	list_show(H);	
	puts("------");
	list_delete(H,-1);	
	list_delete(H,-2);
}
