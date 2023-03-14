typedef char data_t;

typedef struct node {
	data_t data;
	struct node *left;
	struct node *right;
}*bitree;

bitree tree_create();
void preorder(bitree t);
void inorder(bitree t);
void postorder(bitree t);
void layerorder(bitree t);
