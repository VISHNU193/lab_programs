#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct dynamicQ
{
    int *arr;
    int front,rear;
    int size,capacity;
};
bool isFull(struct dynamicQ *q){
    return q->size==q->capacity;
}
bool isEmpty(struct dynamicQ *q){
    return q->size==0;
}
struct dynamicQ * createQueue(int c){
    struct dynamicQ *queue=malloc(sizeof(struct dynamicQ));
    queue->capacity=c;
    queue->arr=(int*)calloc(c,sizeof(int));
    queue->front=0;
    queue->rear=-1;
    queue->size=0;
    return queue;
}

void queueFull(struct dynamicQ *q){
    q->capacity*=2;
    q->arr=realloc(q->arr,q->capacity*sizeof(int));
}
void addq(struct dynamicQ *q,int ele){
    if (isFull(q))
    {
        queueFull(q);
    }
    q->rear=(q->rear+1)%q->capacity;
    q->arr[q->rear]=ele;
    q->size++;
}
int deleteq(struct dynamicQ *q){
    if(isEmpty(q)){
        return -1;
    }
    int item = q->arr[q->front];
    q->front=(q->front+1)%q->capacity;
    q->size--;
    return item;
}
void displayQueue(struct dynamicQ *q){
    if (isEmpty(q)) {
        return;
    }
    printf("Queue elements: ");
    for(int i=q->front;i<q->rear;i=(i+1)%q->capacity){
        printf("%d,",q->arr[i]);
    } 
    printf("%d\n", q->arr[q->rear]);
}


int main(int argc, char const *argv[])
{
    struct dynamicQ *queue=createQueue(5);
    addq(queue,10);
    addq(queue,20);
    addq(queue,30);
    addq(queue,40);
    addq(queue,50);
    addq(queue,60);
    addq(queue,70);
    addq(queue,80);
    addq(queue,80);
    addq(queue,80);
    addq(queue,80);
    addq(queue,80);
    addq(queue,80);
    addq(queue,80);
    addq(queue,80);
    addq(queue,80);
    addq(queue,80);
    addq(queue,80);
    addq(queue,80);
    
    displayQueue(queue);
    printf("deleted %d\n",deleteq(queue));
    printf("deleted %d\n",deleteq(queue));
    printf("deleted %d\n",deleteq(queue));
    displayQueue(queue);
    return 0;
}

