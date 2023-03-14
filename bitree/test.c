#include <stdio.h>
#include "linkqueue.h"

int main() {
	bitree t = tree_create();
	if(NULL == t) {
		printf("malloc failed\n");
		return -1;
	}
	preorder(t);
	puts("");
	inorder(t);
	puts("");
	postorder(t);
	puts("");
	layerorder(t);
	puts("");
}
