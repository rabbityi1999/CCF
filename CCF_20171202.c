#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i=0,len,now,x=0,k;
    int flag[1000]={0};
    scanf("%d %d",&len,&k);
   // printf("k is %d len is %d\n",k,len);
    now=len;
    while(now>1){//len是现在活下来的人
        x++;
       // printf("now is %d,x is %d len is %d i is %d\n",now,x,len,i);
        if((x%10==k)||(x%k==0)){
            now--;
            flag[i]=1;
       // printf("be killed, now is %d,x is %d i is %d killed \n",now,x,i);
        }
        i++;
        while((i>=len)||(flag[i])){
            if(i>=len){
                i=i-len;
            }
            if(flag[i])
                i++;
        }
        //printf("now is %d,x is %d i is %d to be next \n",now,x,i);
    }
    printf("%d",i+1);
    return 0;
}
