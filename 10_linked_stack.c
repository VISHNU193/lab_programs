#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct LinkedStack {
    StackNode* top;
} LinkedStack;


StackNode* createNode(int data) {
    StackNode* newNode = malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void push(LinkedStack * stack , int ele){
    StackNode* newNode = createNode(ele);
    if(stack == NULL){
        stack->top=newNode;
        return;
    }
    newNode->next = stack->top;
    stack->top = newNode;
    return;
}

bool isEmpty(LinkedStack  * stack){
    if(stack->top == NULL){
        return true;
    }
    return false;
}
int pop(LinkedStack * stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return -1;
    }
    
    StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void display(LinkedStack * stack){
    StackNode * temp = stack->top;
    printf("Elements of the stack: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    LinkedStack* stack = (LinkedStack*)malloc(sizeof(LinkedStack));
    stack->top = NULL;
    while (true)
    {
        printf("ENTER CHOICE : 1.push  2.pop  3.display  4.isEmpty  5.exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice){
            case 1: printf("Enter elemnt to be pushed\n");
                    int n;
                    scanf("%d", &n);
                    push(stack, n);
                    break;
            case 2: printf("Element popped : %d\n", pop(stack));
                    break;
            case 3: display(stack);
                    break;
            case 4: printf("Stack is %s\n", isEmpty(stack) ? "empty" : "not empty");
                    break;
            case 5: exit(0);
            default:printf("inavlid choice\n");
                    break;

        }
    }
    
   
    return 0;
}

