#include<stdio.h>

typedef enum {lapren,rparen,plus,minus,times,divide,mod,eos,operand}precedence;
precedence stack[300];

int top = -1;
char expr[100];
int isp[]={0,19,12,12,13,13,13,0};
int icp[]={20,19,12,12,13,13,13,0};

void push(precedence token){
    top++;
    stack[top]=token;
}
precedence pop(){
    return stack[top--];
}

precedence getToken(char *symbol,int *n){
    *symbol=expr[(*n)++];
    switch (*symbol)
    {
    case '(':return lapren;
    case ')':return rparen;
    case '+':return plus;
    case '-':return minus;
    case '*':return times;
    case '/':return divide;
    case '%':return mod;
    case '\0':return eos;

    default:
        return operand;
    }
}

void print_token(precedence token){
    switch (token) {
        case plus:printf("+");break;
        case minus:printf("-");break;
        case times:printf("*");break;
        case divide:printf("/");break;
        case mod:printf("%%");break;
        default:return;
    }
}

void postfix(){
    char symbol;
    int n=0;
    precedence token;
    push(eos);
    for (token=getToken(&symbol, &n); token!=eos; token =getToken(&symbol, &n)) {
        if (token==operand) {
            printf("%c",symbol);

        }
        else if (token==rparen) {
            while (stack[top]!=lapren) {
                print_token(pop());
            
            }
            pop();
        }
        else {
            while (isp[stack[top]] >= icp[token]) {
                print_token(pop());
            
            }
            push(token);
        }
        
    
    }
    while ((token=pop()) != eos) 
        print_token(token);
    
    printf("\n\n\n");    
}

int main(int argc, char const *argv[])
{
    fgets(expr, 100, stdin);
    printf("%s\n",expr);
    postfix();   
    return 0;
}


