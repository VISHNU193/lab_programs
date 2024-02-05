#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *llink,*rlink;
};

typedef struct Node Node;

Node * createNode(int ele){
    Node * newNode = malloc(sizeof(Node));
    newNode->data=ele;
    newNode->llink=NULL;
    newNode->rlink=NULL;
}

void insertFront(Node * first,int item){
    
    Node * temp = createNode(item);
    if(first->rlink==NULL){
        first->rlink = temp;
        first = first->rlink->llink;
        return;
    }
    temp->rlink=first->rlink;
    first->rlink->llink=temp;
    first->rlink=temp;
    temp->llink=first;
}

void insertRear(Node * first,int item){
    Node * temp = createNode(item);
    Node * ptr = first;
    while (ptr->rlink!=NULL)
    {
        ptr=ptr->rlink;
    }
    ptr->rlink=temp;
    temp->llink=ptr;
}

void display(Node * first){
    Node * temp = first->rlink;
    printf("List elements : ");
    while (temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->rlink;
    }
    printf("\n");
}

int deleteRear(Node * first){
    Node * temp = first;
    while (temp->rlink)
    {
        temp=temp->rlink;
    }
    int data= temp->data;
    temp->llink->rlink=NULL;
    free(temp);
}

int deleteFront(Node * first){
    Node * temp = first->rlink;
    if(first->rlink==NULL){
        return -1;
    }
    temp=first->rlink;
    first->rlink=first->rlink->rlink;
    first->rlink->llink=first;
    int data = temp->data;
    free(temp);
    return data;
}

int main(int argc, char const *argv[])
{
    Node * first = malloc(sizeof(Node));
    first->data=0;
    first->llink=NULL;
    first->rlink=NULL;
    // insertFront(first,20);
    // insertFront(first,30);
    // insertRear(first,70);
    // insertRear(first,90);
    // display(first);
    // int x = deleteRear(first);
    // int y = deleteFront(first);
    // display(first);


     while (1)
    {
        printf("ENTER COICE : 1.InsertFront  2.InsertRear 3.DeleteFront 4.DeleteRear 5.Display\n");
        int choice,n;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter element to be inserted at front\n");
                
                scanf("%d",&n);
                insertFront(first,n);
                break;

            
        case 2: printf("Enter element to be inserted at rear\n");
                scanf("%d",&n);
                insertRear(first,n);
                break;
            break;
        case 3:
                printf("Element deleted : %d\n",deleteFront(first));
                break;
        case 4 : printf("Element deleted :%d",deleteRear(first));
                break;
        case 5 : display(first);
                 break;   
        default:
            printf("invalid input\n");
            break;
        }
        
    }
    
    
    return 0;
}
