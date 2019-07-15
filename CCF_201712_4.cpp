 #include <bits/stdc++.h>
 using namespace std;
typedef long long LL;
struct node
{
      LL to, w, type;
};
vector<node>V[505];//每个点为起始结点，都是一个容器，一共505个容器
bool vis[505];//vis数组标记是否已经被访问过了
LL dis[505], xl[505], n;//dis数组保存每个点到源节点的距离,xl表示在xl[i]点之前有多少长度的小路要走
/*len与xl数组的设置，是这一题最为巧妙的一点
通过引入更多数据结构，就可以在原有模型上进行改进，十分巧妙！！！！
数据结构选择对了，一个程序就成功了一半了！！！
这里还有个自己一直都不会注意到的坑点呀，int的范围正负2的15次方，long的范围政府2的31次方
所以这里必须是long long型，否则就会过不了！！！有些编译器long是4/8 字节，int是2/4字节，不统一貌似vc6.0不支持 long long？
*/void dij(LL s)
{
     LL i, j, k;

     for(i = 1; i <= n; i++)//给每个node初始化
     {
         vis[i] = 0;
         xl[i] = 0;
         dis[i] = 1e9;
     }

     dis[1] = 0;

     for(j = 1; j < n; j++)//因为一共n个结点
     {
         LL min1 = 1e9;
         for(i = 1; i <= n; i++)
         {
             if(min1 >= dis[i] && !vis[i])
             {
                 min1 = dis[i];
                 k = i;
             }
         }//k记录下了最小dis的那个node的编号

         vis[k] = 1;//这个是标记遍历过了
         for(i = 0; i < V[k].size(); i++)//以这个dis最小的当前点为起点，开始在里面找合适的node，开始一个个地node看
         {
             LL v = V[k][i].to, len = V[k][i].w, t = V[k][i].type;
             if(vis[v]) continue;
             if(t == 0)//如果是大路
             {
                 if(dis[v] > dis[k] + len)
                 {
                     dis[v] = dis[k] + len;
                     xl[v] = 0;//表示现在到点v的最短路最近的一条不是小路，为之后的做准备
                 }
             }
             else//如果是小道
             {
                 if(!xl[k])//如果之前选择的是大路，小路就这一条
                 {
                     if(dis[v] > dis[k] + len * len)
                     {
                         dis[v] = dis[k] + len * len;
                         xl[v] = len;//表示现在到点v的路，有长度为len的小道
                     }
                 }
                 else//如果之前选择的是小路
                 {
                     LL len1 = (xl[k] + len) * (xl[k] + len) - xl[k] * xl[k];//之所以要减去，是因为小路的连续值不可以重复加
                     if(dis[v] > dis[k] + len1)
                     {
                         dis[v] = dis[k] + len1;
                         xl[v] = xl[k] + len;//表示现在到点v的路，有长度为len+xl[k]的小道
                     }
                 }
             }
         }
     }
}

int main()
{
    LL m, a, b;
    node q;
    scanf("%lld%lld", &n, &m);
    while(m--)
    {
        scanf("%lld%lld%lld%lld", &q.type, &a, &b, &q.w);
        q.to = b;
        V[a].push_back(q);
        q.to = a;
        V[b].push_back(q);//这是一个很大要注意的地方，对于每一条给出的边，要让它的起点和终点都推入相应的容器内（这么看容器是一个二维数组）
    }
    dij(1);
    printf("%lld\n", dis[n]);
    return 0;
}
