#include<stdio.h>
#include<string.h>

int nfind(char string[],char pat[]){
	int lasts = strlen(string) - 1;
	int lastp = strlen(pat) - 1;

	int i,j,start=0,end=lastp;
	for(i=0;end<=lasts;end++,start++){
		if(string[end] == pat[lastp]){
			for(j=0,i=start; j<lastp && string[i]==pat[j];i++,j++);
			if(j==lastp)
				return start;
		}
	}
	return -1;
}

int failure[100];

void fail(char pat[]){
	int n = strlen(pat);
	failure[0]=-1;
	int i,j;
	for(j=1;j<n;j++){
		i=failure[j-1];
		while( (pat[j]!=pat[i+1]) && (i>=0))
			i=failure[i];
		if(pat[j]==pat[i+1])
			failure[j]=i+1;
		else
			failure[j]=-1;
	}
	for(int k=0;k<n;k++)
		printf("\t%d",failure[k]);
	printf("\n");
}


int kmp(char string[],char pat[]){
	int i=0,j=0;
	int lens=strlen(string);
	int lenp = strlen(pat);
	while( i<lens && j<lenp){
		if(string[i]==pat[j]){
		i++;
		j++;

		}
		else if (j==0) i++;
		else j=failure[j-1]+1;
	}
	return (j==lenp ? (i-lenp) : -1);

}


int main(){
	char string[]="abcdabcdbcaaabbdc";
	char pat[]="bbdc";
	printf("%d\n",nfind(string,pat));
	fail(pat);
	printf("%d\n",kmp(string,pat));
	return 0;
}

