#include <stdio.h>
#include <stdlib.h>
//����һ��Сʱ����ʼ������Ŀʱ�е�С����������bug���µ���̬��dedebug������
//�������20170302�ǵ���ӣ�����ȡԿ�׵���Ŀ���񣬶�����Ҫ�����������¼λ�ã�λ�����ţ������λ�ù�ϵ������ͼ�ǹؼ�����
int main()
{
    int n,m,i,j,k,x,y,max;
    int x1[11]={0};
    int x2[11]={0};
    int y1[11]={0};
    int y2[11]={0};
    int pos[11]={0};//������ţ���ʾ��Ӧ��ξ��ε�������
    int output[11]={0};
    int e[11]={0};//��ι�ϵ,��ʾ��Ӧ�����ž��εĲ�α��

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
                max=e[j];//��α��
                k=j;//������
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
