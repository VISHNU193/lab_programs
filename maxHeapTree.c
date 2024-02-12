
#include<stdio.h>
#include<stdlib.h>
#define MAX 200
#define HEAP_EMPTY(n) (!n)
#define HEAP_FULL(n) (n==MAX)

typedef struct{
    int key;
}element;

element heap[MAX];

void push(element item,int *n){
    int i;
    if(HEAP_FULL(*n)){
        fprintf(stderr,"HEAP is FULL\n");
        exit(EXIT_FAILURE);
    }
    i=++(*n);
    while((i!=1)&&(item.key>heap[i/2].key)){
        heap[i]=heap[i/2];
        i=i/2;
    }
    heap[i]=item;
}

element pop(int *n){
    int parent,child;
    element item,temp;
    if(HEAP_EMPTY(*n)){
        fprintf(stderr,"Heap is EMPTY\n");
        exit(EXIT_FAILURE);
    }
    item = heap[1];
    temp=heap[(*n)--];
    parent=1;
    child=2;
    while(child<=*n){
        if((child<*n)&&(heap[child].key<heap[child+1].key))
            child++;
        if(temp.key>=heap[child].key)
            break;
        heap[parent]=heap[child];
        parent=child;
        child*=2;

    }
    heap[parent]=temp;
    return item;
}

void inOrder(int size,int index){
    if(index<size){
        inOrder(size,2*index+1);
        printf("%d ",heap[index].key);
        inOrder(size,2*index+2);
    }
}

int main(int argc, char const *argv[])
{
    int n,choice;
    n=0;
    element ele;
    while (1)
    {
        printf("Enter choice 1.insert 2.delete 3.display\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("nter element to be inserted\n");
                scanf("%d",&(ele.key));
                push(ele,&n);
            break;
        case 2: printf("Element deleted:%d",pop(&n).key);
                break;
        case 3: printf("in order traversal : ");
                inOrder(n,0);
                printf("\n");
                break;
        case 4: goto here;
        default: printf("invalid choice \n");
            break;
        }
    }
    here:
    for (int i = 0; i < n; i++)
    {
        printf("%d->",heap[i]);
    }
    
    
    return 0;
}
