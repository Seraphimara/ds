#define N 128
typedef int data_t;

typedef struct {
	data_t data[N];
	int rear;
	int front;
}sequeue;

sequeue * queue_create();
int enqueue(sequeue *s,data_t data);
data_t dequeue(sequeue *s);
int queue_empty(sequeue *s);
int queue_full(sequeue *s);
int queue_free(sequeue *s);
