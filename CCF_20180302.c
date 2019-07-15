#include <stdio.h>
#include <stdlib.h>
#define L 1
#define R 0
int main()
{
    int i,j,n,t,k,Length,min,index,temp;
    int a[100]={0};
    int b[100]={0};
    int c[100]={0};
    int d[100]={0};
    scanf("%d %d %d",&n,&Length,&t);
    for(j=0;j<n;j++){
        scanf("%d",&a[j]);
        b[j]=R;
        d[j]=a[j];
    }
    for(k=0;k<n;){
        for(i=0;i<n;i++){
            if(d[i]>=0){
                min=d[i];
                index=i;
                for(j=0;j<n;j++){
                    if((d[j]<min)&&(d[j]>0)){
                        min=d[j];
                        index=j;
                    }
                }
                d[index]=-1;//销毁
               // printf("%d \n",index);
                c[k]=index;//c[i]是最小的那个a[i]的i的值;用于索引a[c[0]]是最小的元素值
                k++;
                break;
            }
            else{
                continue;
            }
        }
    }

  /*  for(j=0;j<n;j++){
        printf("%d %d %d \n",a[j],c[j],a[c[j]]);
    }
*/
    for(;t>0;t--){
        for(i=0;i<n;i++){
            if((a[c[i]]==0)&&(b[c[i]]==L)){
                b[c[i]]=R;
            }
            else if((a[c[i]]==Length)&&(b[c[i]]==R)){
                 b[c[i]]=L;
            }
            else if((a[c[i]]==a[c[i+1]])&&(b[c[i]]==R)&&(b[c[i+1]]==L)){
                 b[c[i]]=L;
                 b[c[i+1]]=R;
            }
        }
        for(i=0;i<n;i++){
            if(b[c[i]]==R)
                a[c[i]]=a[c[i]]+1;
            else
                a[c[i]]=a[c[i]]-1;
        }
    }
    for(j=0;j<n;j++){
        printf("%d ",a[j]);
    }
    return 0;
}
