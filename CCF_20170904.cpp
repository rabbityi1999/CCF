#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m;
//注意，这里存储的是从0开始的序号
set<int> out[1100];
set<int> in[1100];
bool inq[1100]={false};
void BFS(int u){
    queue<int> q;
    bool vis[1100]={false};
    q.push(u);
    ll v;
    set<int>::iterator it;
    set<int>::iterator it2;
    while(!q.empty()){
        int v=q.front();//取出的是一个序号
        q.pop();
        //不断增长的集和
        //*it是一个数字
        if(u!=v){
            out[u].insert(v);
            in[v].insert(u);
        }
        if(inq[v]==false){//如果没有定型
            for(it=out[v].begin();it!=out[v].end();it++){//子节点加入队列
                if(inq[*it]==false&&vis[v]==false){//未定的子节点才加入队列
                    q.push(*it);
                    vis[v]=true;//访问的标志
                }
            }
        }
        else{//定型了就不用加入队列了，直接把它的set拿过来
            for(it2=out[v].begin();it2!=out[v].end();it2++){
                if(u!=*it2){
                    out[u].insert(*it2);
                    in[*it2].insert(u);
                }
            }
        }
    }
}

int main()
{
    ll i,j;
    ll a,b;
    cin>>n>>m;
    set<int> temp;
    for(i=0;i<m;i++){
        cin>>a>>b;
        if(a!=b){
            out[a-1].insert(b-1);
            in[b-1].insert(a-1);
        }
    }
    for(i=0;i<n;i++){
        if(inq[i]==false){
            BFS(i);
            inq[i]=true;//定型的标志
        }
    }
    ll num=0;
    for(i=0;i<n;i++){
        if(out[i].size()==n-1||in[i].size()==n-1)
            num++;
    }
    cout<<num<<endl;
    return 0;
}
