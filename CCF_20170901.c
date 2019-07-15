#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,num=0,i,j,k;
    scanf("%d",&n);
    i=n/50;
    j=(n-i*50)/30;
    k=(n-i*50-j*30)/10;
    num=i*7+j*4+k;
    printf("%d",num);
    return 0;
}
