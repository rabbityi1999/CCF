#include <stdio.h>
#include <stdlib.h>
//����һ���ܼ򵥵��⣬�����Լ�debug���˿�1����Сʱ������˵�����ٴ��ˣ�������˼·������α��������ݽṹ�������������д���룡����debug������𣿣���ƹ������ú���
void sort(int a[ ],int num){//��С��������
    int i,j,k,min,index,temp;
    for(i=0;i<num;i++){
        min=a[i];
        index=i;
        for(j=i;j<num;j++){
            if(a[j]<min){
                min=a[j];
                index=j;
            }
        }
        temp=a[i];
        a[i]=a[index];
        a[index]=temp;
    }
}

int main()
{
    int n,k,w,s,c,i,j,p,q,min=10000,max=0,count=0;
    int pos[1001]={0};//0��ʾû���ã�1��ʾ����
    int begin[1001]={0};
    int end[1001]={0};
    int num[1001]={0};
    int key[1001]={0};
    int back[1000]={0};
    scanf("%d %d",&n,&k);


    for(i=1;i<=n;i++){
        pos[i]=i;//��ʾλ��i����Կ��i
        key[i]=i;//��ʾԿ��i������λ��i��
    }
    for(i=0;i<k;i++){
        scanf("%d %d %d",&num[i],&begin[i],&end[i]);
        end[i]=end[i]+begin[i];
        if(begin[i]<min)
            min=begin[i];
        if(end[i]>max)
            max=end[i];
    }

    for(i=min;i<=max;i++){
        for(j=0,count=0;j<k;j++){//��Կ��
            if(end[j]==i){
                back[count]=num[j];//��¼һ��Ҫ����Կ�����
                count++;
            }
        }
        sort(back,count);//������Ŵ�С��������
        for(p=0,q=1;p<count;p++){//�ҵ�һ����Ҫ����Կ��
            for(;q<=n;q++){
                if(pos[q]==0){//posΪ0��ʾλ��Ϊ��
                    pos[q]=back[p];//��Կ����ŷ����Ӧ��λ�õ���
                    key[back[p]]=q;//���Ϊback[p]��Կ��λ��Ϊq;
                    break;
                }
            }
        }
        for(j=0;j<k;j++){//ȡԿ��,�����ҵ���һ��Կ�׶�Ӧλ�ã�
            if(begin[j]==i){
                pos[key[num[j]]]=0;
                key[num[j]]=0;
            }
        }
    }
    for(i=1;i<=n;i++){
        printf("%d ",pos[i]);
    }
    return 0;
}
