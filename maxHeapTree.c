#include<stdio.h>
#include<stdlib.h>

#define MAX 200
#define HEAP_FULL(n) (n==MAX)
#define HEAP_EMPTY(n) (!n)



int heap[MAX];
int n=0;

void push(int item,int *n){
    int i;
    if(HEAP_FULL(*n)){
        fprintf(stderr,"HEAP IS FULL\n");
        exit(EXIT_FAILURE);
    }
    i=++(*n);
    while ((i!=1)&&(item>heap[i/2])){
        heap[i]=heap[i/2];
        i /=2;

    }
    heap[i]=item;
    
}

int pop(int *n){
    int parent,child;
    int item,temp;
    if(HEAP_EMPTY(n)){
        printf("EMpty");
        exit(EXIT_FAILURE);
    }
    item=heap[1];
    temp=heap[(*n)--];
    parent=1;
    child=2;
    while (child<=*n)
    {
        if((child<*n) && (heap[child]<heap[child+1])){
            child++;
        }
        if(temp>=heap[child])
            break;
        heap[parent]=heap[child];
        parent=child;
        child*=2;
    }
    
    heap[parent]=temp;
    return item;
}

void inOrder(int heap[],int size,int index){
    if(index<size){
        printf("%d ",heap[index]);
        inOrder(heap,size,2*index+1);
        inOrder(heap,size,2*index+2);
    }
}
void levelOrderTraversal(int heap[], int size) {
    printf("Level Order Traversal: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    push(10,&n);
    push(20,&n);
    push(30,&n);
    push(40,&n);
    push(50,&n);
    push(60,&n);
    push(70,&n);
    inOrder(heap,n,0);
    printf("\n");
    pop(&n);
    inOrder(heap,n,0);
    printf("\n");
    levelOrderTraversal(heap,n);
    return 0;
}
