#include<stdio.h>
#define MAX 400

typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;

char expr[MAX];
int stack[200];

int top=-1;

precedence get_token(char *symbol,int *n){
	*symbol=expr[(*n)++];
	switch(*symbol){
		case '(':return lparen;
		case ')':return rparen;
		case '+':return plus;
		case '-':return minus;
		case '*':return times;
		case '/':return divide;
		case '%':return mod;
		case '\0':return eos;
		default: return operand;
	}
}

void push(int num){
	stack[++top]=num;
}

int pop(){
	return stack[top--];
}

int eval(){
	precedence token;
	char symbol;
	int op1,op2;
	int n=0;
	token = get_token(&symbol,&n);
	while(token!=eos){
		if(token == operand)
			push(symbol-'0');
		else{
			op1=pop();
			op2=pop();
			switch(token){
				case plus:printf("%d\n",op1+op2);
				       	push(op1+op2);
					   break;
				case minus: push(op1-op2);
					    printf("%d\n",op1-op2);
					    break;
				case times: push(op1*op2);
					    printf("%d\n",op1*op2);
					    break;
				case divide:push(op2/op1);
					    printf("%d\n",op2/op1);
					    break;
				case mod:push(op1%op2);
					 printf("%d\n",op1%op2);
					 break;
			}
		}
		token = get_token(&symbol,&n);
	}
	return pop();
}

int main(){
	int res;
	printf("\n Enter the postfix expression to be evaluatede\n");
	scanf("%s",expr);
	res = eval();
	printf("\n After evaluation : %d\n",res);
	return 0;
}

