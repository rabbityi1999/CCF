#include <stdio.h>
#include <stdlib.h>
//写代码加debug花了30min，构思算法20min
int main()
{
    int n,m,i,j,k,p,q,x,y;
    int pos[1001]={0};
    int stu[1001]={0};
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=1;i<=n;i++){
        pos[i]=i;
        stu[i]=i;
    }
    for(i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        if(y<0){
            y=-y;
            p=stu[x];//p是需要移动的学生的位置
            for(j=1;j<=y;j++){//将所有学生向后移动
                stu[pos[p-j]]++;//在p-j位置，学生位置编号加一
                pos[p-j+1]=pos[p-j];//是前一个位置的学生编号
            }
            stu[x]=stu[x]-y;
            pos[p-y]=x;
        }
        else{
            q=y;
            p=stu[x];
            for(j=1;j<=q;j++){
                stu[pos[p+j]]--;
                pos[p+j-1]=pos[p+j];
            }
            stu[x]=stu[x]+q;
            pos[p+q]=x;
        }
    }
    for(i=1;i<=n;i++)
        printf("%d ",pos[i]);
    return 0;
}
