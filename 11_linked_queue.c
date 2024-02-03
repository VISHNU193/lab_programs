#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct LinkedQueue {
    QueueNode* front;
    QueueNode* rear;
} LinkedQueue;

QueueNode* createNode(int data) {
    QueueNode* newNode = malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addq(LinkedQueue * queue,int ele){
    QueueNode* newNode = createNode(ele);
    if (queue->rear == NULL)
    {
        queue->rear = newNode;
        queue->front = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;    

}

int deleteq(LinkedQueue * queue)
{   
    if(queue->front->next == NULL){
        queue->rear=NULL;
    }
    if (queue->front == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    QueueNode *temp = queue->front;
    int data = temp ->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

void displayq(LinkedQueue * queue)
{
    QueueNode * temp = queue->front;
    printf("Elements of the queue: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
}

int main(int argc, char const *argv[])
{
    LinkedQueue* queue = malloc(sizeof(LinkedQueue));
    queue->front = NULL;
    queue->rear = NULL;
    while (true)
    {
        printf("Enter choice : 1. Add  2. Delete  3. Display\n");
        int choice;
        scanf("%d",&choice);
        switch (choice){
            case 1: printf("Enter element to be added\n");
                    int n;
                    scanf("%d", &n);
                    addq(queue, n);
                    break;
            case 2: printf("Element deleted : %d\n", deleteq(queue));
                    break;
            case 3: displayq(queue);
                    break;
            default:printf("inavlid choice\n");

        }
    }
    
    return 0;
}
