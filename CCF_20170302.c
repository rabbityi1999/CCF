#include <stdio.h>
#include <stdlib.h>
//д�����debug����30min����˼�㷨20min
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
            p=stu[x];//p����Ҫ�ƶ���ѧ����λ��
            for(j=1;j<=y;j++){//������ѧ������ƶ�
                stu[pos[p-j]]++;//��p-jλ�ã�ѧ��λ�ñ�ż�һ
                pos[p-j+1]=pos[p-j];//��ǰһ��λ�õ�ѧ�����
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
