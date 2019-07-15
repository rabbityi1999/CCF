//#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
/*
时间1h
易错点一：【必须保证找到最优解后可以暂停退出】忘记添加DFS的限制条件，如果当前时间超标了就不应该继续走了——已经找到了最优解就立马终止导致的死循环
易错点二：【必须保证可以在有限的时间内找到最优解】兵分四路应该是同时的，不应该写成if else结果只进入了一路一直没有找到最优解
傻傻地将begin和end变成关键字了，写重了难怪编译通过不了
以后提交之前写个auto 看看自己的编译器用的是哪个版本的
10分的原因是代码超时了，不可以这样写的
20分加入了一个三维数组来剪枝
后来发现，就是不应该用深搜呀，会超时的嘞，应该用广搜
*/
using namespace std;
#define N 200 //改大点
int begin0[N]={0};
int end0[N]={0};
int pos[N][N]={0};
long long minTime=1000000000;
int n,m;
int visited[N+1][N+1][300+1]={0};
int safe(int i,int j,int time){
    if(pos[i][j]==0)
        return 1;
    else{
        if(time<begin0[pos[i][j]-1]||time>end0[pos[i][j]-1])
            return 1;
    }
    return 0;
}

void DFS(long long time,int i,int j){//去掉1后的行数和列数
    visited[i][j][time]=1;
    if(i==n-1&&j==m-1){
        if(time<minTime)
            minTime=time;
    }
    else{
        if(minTime>time+1){//如果已经有别的点到了，那么就不用走了，否则会死循环
            if(i<n-1 && safe(i+1,j,time+1)&&visited[i+1][j][time+1]==0){//向下
                //visited[i+1][j][time+1]=1;//表示考虑过这一秒钟的情况了
                DFS(time+1,i+1,j);

            }
            if(j<n-1 && safe(i,j+1,time+1)&&visited[i][j+1][time+1]==0){//向右
                //visited[i][j+1][time+1]=1;
                DFS(time+1,i,j+1);
            }
            if(0<i && safe(i-1,j,time+1)&&visited[i-1][j][time+1]==0){//向上
                //visited[i-1][j][time+1]=1;
                DFS(time+1,i-1,j);
            }
            if(0<j && safe(i,j-1,time+1)&&visited[i][j-1][time+1]==0){//向左
                //visited[i][j-1][time+1]=1;
                DFS(time+1,i,j-1);

            }
        }
    }
}
int main()
{
    auto d = 1;
    int t,i,r,c,a,b;
    cin>>n>>m>>t;
    for(i=0;i<t;i++){
        cin>>r>>c>>a>>b;//小心行数和列数的转换
        pos[r-1][c-1]=i+1;//存入序号
        begin0[i]=a;
        end0[i]=b;
    }
    DFS(0,0,0);
    cout << minTime << endl;
    return 0;
}
