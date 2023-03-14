#include "sqstack.h"
#include "linkqueue.h"
#include <stdio.h>

int check(linkqueue lq) {
	if (lq == NULL) {
		printf("lq is NULL\n");
		return -1;
	}
	linklist p = lq->front->next;
	while(p->next && p) {
		if(p->next->data > p->data)
			p = p->next;
		else 
			return 0;
	}
	return 1;
	
}
int main() {
	linkqueue lq = queue_create();
	sqstack *s_min, *s_five, *s_hour;
	s_min = stack_create(4);
	s_five = stack_create(11);
	s_hour = stack_create(11);
	int min = 0, value;
	if(lq == NULL || s_min == NULL || s_five == NULL || s_hour == NULL) {
		printf("malloce failed \n");
		return -1;
	}
	for(int i=1; i<=27; ++i) {
		enqueue(lq, i);
	}
	while(1) {
		min++;
		value = dequeue(lq);
		if(!stack_full(s_min)) {
			stack_push(s_min,value);
		}else {
			while(!stack_empty(s_min)) {
				enqueue(lq,stack_pop(s_min));
			}
			if(!stack_full(s_five)) {
				stack_push(s_five,value);
			}else {
				while(!stack_empty(s_five)){
					enqueue(lq,stack_pop(s_five));
				}
				if(!stack_full(s_hour)) {
					stack_push(s_hour,value);
				}else {
					while(!stack_empty(s_hour)) {
						enqueue(lq,stack_pop(s_hour));
					}
					enqueue(lq,value);
					if(1 == check(lq)) {
						break;
					}
				}
			}
		}
	}
	printf("total mins: %d\n",min);

}
