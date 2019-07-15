#include <stdio.h>
#include <stdlib.h>
#define C 0
#define R 1
#define Y 2
#define G 3
/*
错误点1：如果是10的5次方*10的6次方=10^11>2^32一定要用long long！！！！！！
手误有两处！！！要把不用的变量删掉！！！！
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
    else if(now>=T[R]&&now<(T[G]+T[R]))//这里写成了now<T[G]！！！！！严重错误！！！！
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
    all=T[R]+T[Y]+T[G];//这里写成了all=r+y+g！！！！严重错误！！！！！把没有初始化的变量全部删掉！！！！！！
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
