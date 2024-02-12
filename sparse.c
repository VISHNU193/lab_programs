#include<stdio.h>

#define max_terms 101
#define max_col 50

typedef struct {
	int row,col,value;
}term;

term a[max_terms],b[max_terms],sum[max_terms],mult[max_terms];

void transpose(term a[],term b[]){
	int n,i,j,currentb;
	n=a[0].value;
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].value=n;
	if(n>0){
		currentb=1;
		for(i=0;i<a[0].col;i++)
			for(j=0;j<=n;j++)
				if(a[j].col==i){
					b[currentb].row=a[j].col;
					b[currentb].col=a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
				}
	}
}



void fast_transpose(term a[],term b[]){
	int row_terms[max_col],starting_pos[max_col];
	int i,j,num_cols=a[0].col,num_terms=a[0].value;
	b[0].row=num_cols;
	b[0].col=a[0].row;
	b[0].value=num_terms;
	if(num_terms>0){
		for(i=0;i<num_cols;i++)
			row_terms[i]=0;
		for(i=1;i<=num_terms;i++)
			row_terms[a[i].col]++;
		starting_pos[0]=1;
		for(i=1;i<num_cols;i++)
			starting_pos[i]=starting_pos[i-1]+row_terms[i-1];
		for(i=1;i<=num_terms;i++){
			j=starting_pos[a[i].col];
			starting_pos[a[i].col]++;
			b[j].row=a[i].col;
			b[j].col=a[i].row;
			b[j].value=a[i].value;
		}
	}
}


void readSparse(term a[],int r,int c){
	int i,j,k=1,item;
	a[0].row=r;
	a[0].col=c;
	for(i=0;i<r;i++){
		                 
		for(j=0;j<c;j++){
			scanf("%d",&item);
			if(item!=0){
			a[k].row=i;
			a[k].col=j;
			a[k].value=item;
			k++;
			}
		}
	}

	
	a[0].value=k-1;
}

void displaySparse(term a[]){
	int n=a[0].value+1;
	printf("\nROW\tCOL\tVALUE");
	for(int i=0;i<n;i++)
		printf("\n%d\t%d\t%d",a[i].row,a[i].col,a[i].value);
}

void addMatrix(term a[],term b[]){
	
}


int main(){
	printf("\nEnter size of matrix ");
	int m,n;
	scanf("%d%d",&m,&n);
	printf("\nEnter Sparse matrix");

	readSparse(a,n,m);
	printf("\nOriginal matrix");
	displaySparse(a);
	printf("\nEnter choice 1 for Transpose , 2 for Fast_transpose");
	int choice;
	scanf("%d",&choice);
	switch(choice){
		case 1:printf("\nTransposed matrix");
		       transpose(a,b);
		       displaySparse(b);
		       break;
		case 2:printf("\nFast transposed matrix");
		       fast_transpose(a,b);
		       displaySparse(b);
	}	
	return 0;
}
