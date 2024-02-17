#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int * arr= calloc(5,sizeof(int));
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    arr[3]=40;
    arr[4]=50;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t",arr[i]);
    }
    arr=realloc(arr,)
    
    return 0;
}
