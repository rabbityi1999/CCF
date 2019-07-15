#include <stdio.h>
#include <stdlib.h>
//这是一道很简单的题，但是自己debug花了快1个半小时！！！说过多少次了！！代码思路清晰，伪代码和数据结构都定义清楚了再写代码！！！debug很舒服吗？？设计工作不好好做
void sort(int a[ ],int num){//从小到大排序
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
    int pos[1001]={0};//0表示没有用，1表示用了
    int begin[1001]={0};
    int end[1001]={0};
    int num[1001]={0};
    int key[1001]={0};
    int back[1000]={0};
    scanf("%d %d",&n,&k);


    for(i=1;i<=n;i++){
        pos[i]=i;//表示位置i放着钥匙i
        key[i]=i;//表示钥匙i放在了位置i处
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
        for(j=0,count=0;j<k;j++){//还钥匙
            if(end[j]==i){
                back[count]=num[j];//记录一下要还的钥匙序号
                count++;
            }
        }
        sort(back,count);//按照序号从小到大排序
        for(p=0,q=1;p<count;p++){//找到一把需要还的钥匙
            for(;q<=n;q++){
                if(pos[q]==0){//pos为0表示位置为空
                    pos[q]=back[p];//将钥匙序号放入对应的位置当中
                    key[back[p]]=q;//序号为back[p]的钥匙位置为q;
                    break;
                }
            }
        }
        for(j=0;j<k;j++){//取钥匙,还得找到那一把钥匙对应位置；
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
