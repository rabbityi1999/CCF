#include <stdio.h>
#include <stdlib.h>
//不到一个小时，开始看到题目时有点小绝望，本着bug不怕的心态，dedebug更健康
//这道题与20170302那道插队，还有取钥匙的题目很像，都是需要用两个数组记录位置，位置与编号，编号与位置关系，画画图是关键！！
int main()
{
    int n,m,i,j,k,x,y,max;
    int x1[11]={0};
    int x2[11]={0};
    int y1[11]={0};
    int y2[11]={0};
    int pos[11]={0};//输入序号，表示对应层次矩形的输入编号
    int output[11]={0};
    int e[11]={0};//层次关系,表示对应输入编号矩形的层次编号

    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
        pos[i]=i;
        e[i]=i;
    }
    for(i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        for(j=1,max=0;j<=n;j++){
            if((x1[j]<=x)&&(y1[j]<=y)&&(x2[j]>=x)&&(y2[j]>=y)&&(e[j]>max)){
                max=e[j];//层次编号
                k=j;//输入编号
            }
        }

        if(max==0){
            output[i]=-1;
        }
        else{
            output[i]=k;
            for(j=1;j<=n-max;j++){
                e[pos[max+j]]--;
                pos[max+j-1]=pos[max+j];
            }
            e[k]=n;
            pos[n]=k;
        }
    }
    for(i=1;i<=m;i++){
        if(output[i]!=-1){
            printf("%d\n",output[i]);

        }
        else
            printf("IGNORED\n");
    }

    return 0;
}
