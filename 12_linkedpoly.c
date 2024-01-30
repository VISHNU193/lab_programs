#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define compare(x,y) ((x)>(y)?1:((x)<(y)?-1:0))

typedef struct PolyNode {
    int exp;
    int coef;
    struct PolyNode* next;
} PolyNode;

PolyNode* createNode(int exponent, int coefficient) {
    PolyNode* newNode = malloc(sizeof(PolyNode));
    newNode->exp=exponent;
    newNode->coef=coefficient;
    newNode->next = NULL;
    return newNode;
}

void addPolyNode(PolyNode **p, int exponent, int coefficient) {
    PolyNode* newNode = createNode(exponent, coefficient);
    if (*p == NULL) {
        *p = newNode;
    } 
    else {
        PolyNode* temp = *p;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

PolyNode* readPoly(PolyNode **p){
    printf("Enter number of terms in the polynomial: ");
    int n;
    scanf("%d", &n);
    int exponent, coefficient;
    while (n>0)
    {
        printf("Enter exponent and coefficient: ");
        scanf("%d %d", &exponent, &coefficient);
        addPolyNode(p, exponent, coefficient);
        n--;
    }
    return *p;
}

PolyNode * addPoly(PolyNode **p1, PolyNode **p2){
    PolyNode **sum = malloc(sizeof(PolyNode));
    *sum = NULL;
    PolyNode *p1_temp = malloc(sizeof(PolyNode));
    PolyNode *p2_temp = malloc(sizeof(PolyNode));
    p1_temp = *p1;
    p2_temp = *p2;
    while (p1_temp!=NULL && p2_temp!=NULL)
    {
        
        // if (p1_temp->exp > p2_temp->exp){
        //     addPolyNode(sum, p1_temp->exp, p1_temp->coef);
        //     p1_temp = p1_temp->next;
        // }
        // else if (p1_temp->exp < p2_temp->exp){
        //     addPolyNode(sum, p2_temp->exp, p2_temp->coef);
        //     p2_temp = p2_temp->next;
        // }
        // else if (p1_temp->exp == p2_temp->exp){
            
        //     addPolyNode(sum, p1_temp->exp, p1_temp->coef+p2_temp->coef);
        //     p1_temp = p1_temp->next;
        //     p2_temp = p2_temp->next;
        // }
        switch (compare(p1_temp->exp, p2_temp->exp))
        {
        case 1:addPolyNode(sum, p1_temp->exp, p1_temp->coef);
              p1_temp = p1_temp->next;
            break;
        case -1:
            addPolyNode(sum, p2_temp->exp, p2_temp->coef);
            p2_temp = p2_temp->next;
            break;
        case 0:
            addPolyNode(sum, p1_temp->exp, p1_temp->coef+p2_temp->coef);
            p1_temp = p1_temp->next;
            p2_temp = p2_temp->next;
            break;
        
        default:
            break;
        }
    
    }

    return *sum;
}


void display(PolyNode *p){
    PolyNode *temp = p;
    printf("Polynomial: ");
    while (temp!=NULL){
        printf("%dx^%d + ", temp->coef, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    PolyNode *p1, *p2, *sum;
    p1=p2=sum=NULL;
    p1=readPoly(&p1);
    p2=readPoly(&p2);
    display(p1);
    display(p2);
    sum=addPoly(&p1, &p2);
    display(sum);

    return 0;
}
