#include <stdio.h>
#include <stdlib.h>
#define C 0
#define R 1
#define Y 2
#define G 3
/*
�����1�������10��5�η�*10��6�η�=10^11>2^32һ��Ҫ��long long������������
����������������Ҫ�Ѳ��õı���ɾ����������
*/
long long T[4]={0};
long long a[1005]={0};
long long all;
long long cal(long long k,long long t,long long time){
    long long now;
    if(k==R){
        now=(T[k]-t+time)%all;
    }
    else if(k==G){
        now=(T[k]-t+T[R]+time)%all;
    }
    else if(k==Y){
        now=(T[k]-t+T[R]+T[G]+time)%all;
    }
    else
        return t;//road won't change

    if(now>=0&&now<T[R]){
        return (T[R]-now);
    }
    else if(now>=T[R]&&now<(T[G]+T[R]))//����д����now<T[G]�������������ش��󣡣�����
        return(0);
    else
        return (T[R]+T[G]+T[Y]-now+T[R]);
}
int main()
{
    long long k,t;
    long long time=0;
    long long n,i;
    scanf("%lld %lld %lld",&T[R],&T[Y],&T[G]);
    all=T[R]+T[Y]+T[G];//����д����all=r+y+g�����������ش��󣡣���������û�г�ʼ���ı���ȫ��ɾ��������������
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld %lld",&k,&t);
        t=cal(k,t,time);
        //printf("%d t=%lld\n",i,t);
        time=time+t;
    }
    printf("%lld",time);
    return 0;
}
