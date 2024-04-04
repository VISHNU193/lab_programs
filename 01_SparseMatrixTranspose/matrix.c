#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct matrix{
	int row_value,column_value,value;
};

typedef struct matrix matrix;

void getMatrix(matrix a[],int rows,int columns){
	int i,j,k,input;
	k=1;
	a[0].row_value=rows;
	a[0].column_value=columns;
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			scanf("%d",&input);
			if(input!=0){
				a[k].row_value=i;
				a[k].column_value=j;
				a[k].value=input;
				k++;
			}
		}
	}
	a[0].value=k-1;
}

void printMatrix(matrix a[]){
	int n=a[0].value;
	printf("ROW\tCOLUMN\tVALUE\n");
	for(int i=0;i<=n;i++){
		printf("%d\t%d\t%d\n",a[i].row_value,a[i].column_value,a[i].value);
	}
}

matrix* simpleTranspose(matrix a[],matrix b[]){
	int i,j,k,n;
	b[0].row_value=a[0].column_value;
	b[0].column_value=a[0].column_value;
	b[0].value=n=a[0].value;
	k=1;
	if(n>0){
		for(i=0;i<a[0].column_value;i++){
			for(j=1;j<=n;j++){
				if(a[j].column_value==i){
					b[k].column_value=a[j].row_value;
					b[k].row_value= a[j].column_value;
					b[k].value=a[j].value;
					k++;
				}
			}
		}
	}
}


void fast_Transpose(matrix a[],matrix b[]){
	int i,j,n;
	int row_terms[MAX]={0};
	int position[MAX]={0};

	b[0].row_value=a[0].column_value;
	b[0].column_value=a[0].row_value;
	b[0].value=n=a[0].value;

	if(n>0){
		for(i=0;i<a[0].column_value;i++)
			row_terms[i]=0;
		for(i=1;i<=n;i++)
			row_terms[a[i].column_value]++;
			
		for(i=0;i<n;i++)
			printf("\t%d",row_terms[i]);
		printf("\n");
		position[0]=1;
		for(i=1;i<=a[0].column_value;i++)
			position[i]=position[i-1]+row_terms[i-1];
		for(i=0;i<10;i++)
		printf("\t%d",position[i]);
			
		
		printf("\n");
		for(i=1;i<=n;i++){
			j=position[a[i].column_value]++;
			b[j].column_value=a[i].row_value;
			b[j].row_value=a[i].column_value;
			b[j].value=a[i].value;
		}
	}

}


	
int main(){
	matrix m1[MAX];
	matrix m2[MAX];
	matrix m3[MAX];
	getMatrix(m1,3,3);
	printMatrix(m1);
	simpleTranspose(m1,m2);
	printMatrix(m2);
	fast_Transpose(m1,m3);
	printMatrix(m3);

	return 0;
}	
