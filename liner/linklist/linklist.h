typedef int data_t;
typedef struct node {
	data_t data;
	struct node *next;
}listnode, * linklist;

linklist list_create();
int list_tail_insert(linklist H,data_t data);
int list_head_insert(linklist H,data_t data);
int list_insert(linklist h,data_t data,int pos);
linklist list_get(linklist H, int pos);
int list_delete(linklist H,int pos);
int list_show(linklist H);
int list_delete(linklist H,int pos);
int list_free(linklist H);
int list_reverse(linklist H);
int list_merge(linklist H1,linklist H2);
linklist list_adjmax(linklist H);
