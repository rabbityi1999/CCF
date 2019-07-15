#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
/*
1、每个方格的的字符不同，能走的方向也不同。因此需要有一个函数根据当前方格字符确定能走的方向。

2、对于性质1，通过从起点开始BFS，用一个数组v1记录能走到的方格，再用一个四维的able[x1][y1][x2][y2]数组表示能从(x1,y1)走到(x2,y2)，下一步需要用到。

3、对于性质2，发现如果直接求是比较困难的，而如果转而去求从某个方格出发能够到达终点的方格，相对而言会比较简单。

从终点开始BFS，利用able数组，用v2数组记录能够到达终点的方格。那么剩下的方格就是不能到达终点的了。

4、统计v1标记了且没有被v2标记的方格数，得到答案。
*/
using namespace std;

struct P{
    int x,y;
};

char Map[55][55];
int mov[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
bool able[55][55][55][55],v1[55][55],v2[55][55];

void get(P a,int &st,int &ed){
    if(Map[a.x][a.y]=='-') st=2,ed=4;
    else if(Map[a.x][a.y]=='|') st=0,ed=2;
    else if(Map[a.x][a.y]=='.') st=0,ed=1;
    else st=0,ed=4;
}
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i) scanf("%s",Map[i]);//输入就极其精巧，省代码，通过字符串的形式读入，非常新颖
    queue<P> q;//一定要多多用STL库里面好用的模板，结构定义的好是会事半功倍的
    P p,e;
    for(i=0;i<n;++i)
    for(j=0;j<m;++j){
        if(Map[i][j]=='S'){
            p.x=i,p.y=j;
            q.push(p);
        }
        else if(Map[i][j]=='T'){
            e.x=i,e.y=j;
        }
    }
    memset(v1,0,sizeof(v1));//用memset数组初始化，比用for循环数组初始化强多了
    memset(v2,0,sizeof(v2));
    memset(able,0,sizeof(able));
    v1[p.x][p.y]=1;
    while(!q.empty()){//一直持续到q为空，q的起始就一个起点
        p=q.front();q.pop();
        P tem=p;
        int st,ed;
        get(p,st,ed);
        for(i=st;i<ed;++i){//BFS的思想：对于从队列pop出来的点，将所有情况都考虑一遍，遍历
            tem.x=p.x+mov[i][0];
            tem.y=p.y+mov[i][1];
            if(tem.x>=0&&tem.y>=0&&tem.x<n&&tem.y<m&&Map[tem.x][tem.y]!='#'){
                able[p.x][p.y][tem.x][tem.y]=1;
                if(!v1[tem.x][tem.y]){
                    v1[tem.x][tem.y]=1;
                    q.push(tem);//别忘记了，到达的点重新入栈
                }
            }
        }
    }
    if(!v1[e.x][e.y]) {puts("I'm stuck!");return 0;}//玩家初始状态就不可达终点
    int ans=0;
    q.push(e);
    v2[e.x][e.y]=1;
    while(!q.empty()){
        p=q.front();q.pop();
        P tem=p;
        for(i=0;i<4;++i){
            tem.x=p.x+mov[i][0];//able数组真的很重要呀！！！借助able数组.able数组要和可达的位置对应，既要从终点可达（BFS，任意四个方向），又要可达终点，对应
            tem.y=p.y+mov[i][1];
            if(tem.x>=0&&tem.y>=0&&tem.x<n&&tem.y<m&&Map[tem.x][tem.y]!='#'&&able[tem.x][tem.y][p.x][p.y]&&!v2[tem.x][tem.y]){
                v2[tem.x][tem.y]=1;
                q.push(tem);
            }
        }
    }
    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
            if(v1[i][j]&&!v2[i][j]) ++ans;
    printf("%d\n",ans);
    return 0;
}
