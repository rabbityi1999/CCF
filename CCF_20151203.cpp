#include <bits/stdc++.h>
using namespace std;
int n,m;
char MAP[110][110];
struct node{
    int x;
    int y;
    int vis;
};

void BFS(int a,int b,char ch){
    queue<node> Q;
    int vis[110][110]={0};
    node start,next,NEW;
    start.x=a;
    start.y=b;
    vis[a][b]=true;
    MAP[a][b]=ch;
    Q.push(start);
    while(!Q.empty()){
        next=Q.front();
        Q.pop();
        a=next.x;
        b=next.y;
        if(a-1>=0){
                NEW.x=a-1;
                NEW.y=b;
                NEW.vis=1;
                if(MAP[NEW.x][NEW.y]!='|'&&MAP[NEW.x][NEW.y]!='-'&&MAP[NEW.x][NEW.y]!='+'&&vis[NEW.x][NEW.y]!=true){
                    MAP[NEW.x][NEW.y]=ch;
                     vis[NEW.x][NEW.y]=true;
                    Q.push(NEW);
                }
        }
        if(a+1<=m-1){
                NEW.x=a+1;
                NEW.y=b;
                NEW.vis=1;
                if(MAP[NEW.x][NEW.y]!='|'&&MAP[NEW.x][NEW.y]!='-'&&MAP[NEW.x][NEW.y]!='+'&&vis[NEW.x][NEW.y]!=true){
                    MAP[NEW.x][NEW.y]=ch;
                     vis[NEW.x][NEW.y]=true;
                    Q.push(NEW);
                }
        }
        if(b-1>=0){
                NEW.x=a;
                NEW.y=b-1;
                NEW.vis=1;
                if(MAP[NEW.x][NEW.y]!='|'&&MAP[NEW.x][NEW.y]!='-'&&MAP[NEW.x][NEW.y]!='+'&&vis[NEW.x][NEW.y]!=true){
                    MAP[NEW.x][NEW.y]=ch;
                     vis[NEW.x][NEW.y]=true;
                    Q.push(NEW);
                }
        }
        if(b+1<=n-1){
                NEW.x=a;
                NEW.y=b+1;
                NEW.vis=1;
                if(MAP[NEW.x][NEW.y]!='|'&&MAP[NEW.x][NEW.y]!='-'&&MAP[NEW.x][NEW.y]!='+'&&vis[NEW.x][NEW.y]!=true){
                    MAP[NEW.x][NEW.y]=ch;
                     vis[NEW.x][NEW.y]=true;
                    Q.push(NEW);
                }
        }
    }
}
int main()
{
    int i,j,q,kind,x1,x2,y1,y2,MAX,MIN;
    string s;
    char ch;
    cin>>n>>m>>q;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            MAP[i][j]='.';
        }
    }
    while(q>0){
        cin>>kind;
        if(kind==0){
            cin>>x1>>y1>>x2>>y2;
            if(x1==x2){//»­ÊúÏß
                if(y1>y2){
                    MIN=y2;
                    MAX=y1;
                }
                else{
                    MIN=y1;
                    MAX=y2;
                }
                for(i=MIN;i<=MAX;i++){
                    if(MAP[m-i-1][x1]!='-')
                        MAP[m-i-1][x1]='|';
                    else
                        MAP[m-i-1][x1]='+';
                }
            }
            else{
                if(x1>x2){
                    MIN=x2;MAX=x1;
                }
                else{
                    MIN=x1;MAX=x2;
                }
                for(i=MIN;i<=MAX;i++){
                    if(MAP[m-y1-1][i]!='|')
                        MAP[m-y1-1][i]='-';
                    else
                        MAP[m-y1-1][i]='+';
                }
            }
        }
        else{
            cin>>x1>>y1>>s;
            ch=s[0];
            BFS(m-y1-1,x1,ch);
        }
        q--;
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<MAP[i][j];
        }
        cout<<endl;
    }
    return 0;
}
