//#include <iostream>
/*
fill 函数？
*/
#include <bits/stdc++.h>
#define N 501
#define INF 1000000
using namespace std;
long long cost[N];//总疲劳
long long tired[N]={0};//已经走小道连续了多久
bool visted[N]={false};
long long dis[501][501];
long long kind[501][501]={0};
int main()
{
    long long i,j,n,m,u,v,MIN;
    long long t,a,b,c;
    cin>>n>>m;
   for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            dis[i][j]= INF;
        }
    }


    for(i=0;i<m;i++){
        cin>>t>>a>>b>>c;
        kind[a-1][b-1]=t;
        kind[b-1][a-1]=t;
        dis[a-1][b-1]=c;
        dis[b-1][a-1]=c;
    }

    fill(cost,cost+N,INF);
    cost[0]=0;
    for(i=0;i<n;i++){
        //找到未访问的结点当中cost最小的
        u=-1,MIN=INF;
        for(j=0;j<n;j++){
            if(visted[j]==false && cost[j]<MIN){
                u=j;
                MIN=cost[j];
            }
        }
        visted[u]=true;
        for(v=0;v<n;v++){
            if(visted[v]==false && dis[u][v]!=INF){
                if(kind[u][v]==0 && dis[u][v]+cost[u]<cost[v]){
                    cost[v]=cost[u]+dis[u][v];
                    tired[v]=0;
                }
                if(kind[u][v]==1 && cost[u]-(tired[u]*tired[u])+(tired[u]+dis[u][v])*(tired[u]+dis[u][v])<cost[v]){
                    cost[v]=cost[u]-(tired[u]*tired[u])+(tired[u]+dis[u][v])*(tired[u]+dis[u][v]);
                    tired[v]=tired[u]+dis[u][v];
                }
            }
        }
    }
    cout << cost[n-1]<< endl;
    return 0;
}
