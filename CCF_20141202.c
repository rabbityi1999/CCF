#include <stdio.h>
#include <stdlib.h>
//这一道题是分类讨论题，我觉得自己的方向没有问题，但是看到别人用direction的感觉还是会简单一些，只需要考虑下一步
//虽然最后ac了，但是花了2个小时的时间！！！相当不开心，因为开始设计思路时没有考虑那么多
//长教训了！！！以后必须在设计算法（尤其是分类讨论型题目）时，必须实现想好，画好所有情况再写！！
int main()
{
    int a[500][500]={0};
    int i=0,j=0,k,p,q,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    i=0;
    j=0;
    for(k=0;k<n*n;k++){
        printf("%d ",a[i][j]);
        if((i==n-1)&&(j==n-1))
            break;
        if(((i==0)&&(j%2==1))||((j==n-1)&&(i%2==1)&&(n%2==1))||((j==n-1)&&(i%2==0)&&(n%2==0))){//左下
            if((i==0)&&(j%2==1))
                q=j;
            else
                q=n-i-1;
            for(p=1;p<=q-1;p++){
                printf("%d ",a[i+p][j-p]);
            }
            if((i==0)&&(j%2==1))
                i=i+j;
            else
                i=n-1;
            j=j-q;
        }
        else if(((i==0)&&(j%2==0)&&(j!=n-1))||((i==n-1)&&(j%2==1)&&(n%2==1))||((i==n-1)&&(j%2==0)&&(n%2==0))){
            j++;
        }
        else if(((j==0)&&(i%2==0)&&(i!=0))||((i==n-1)&&(j%2==0)&&(n%2==1))||((i==n-1)&&(j%2==1)&&(n%2==0))){
            if((j==0)&&(i%2==0)&&(i!=0))
                q=i;
            else
                q=n-j-1;
            for(p=1;p<=q-1;p++){
                printf("%d ",a[i-p][j+p]);
            }
            if((j==0)&&(i%2==0)&&(i!=0))
                j=j+i;
            else
                j=n-1;
            i=i-q;
        }
        else if(((j==0)&&(i%2==1)&&(i!=n-1))||((j==n-1)&&(i%2==0)&&(n%2==1))||((j==n-1)&&(i%2==1)&&(n%2==0))){//下移
            i++;
        }
        else{
            printf("error");
        }
    }
    return 0;
}
