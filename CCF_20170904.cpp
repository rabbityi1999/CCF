#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m;
//ע�⣬����洢���Ǵ�0��ʼ�����
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
        int v=q.front();//ȡ������һ�����
        q.pop();
        //���������ļ���
        //*it��һ������
        if(u!=v){
            out[u].insert(v);
            in[v].insert(u);
        }
        if(inq[v]==false){//���û�ж���
            for(it=out[v].begin();it!=out[v].end();it++){//�ӽڵ�������
                if(inq[*it]==false&&vis[v]==false){//δ�����ӽڵ�ż������
                    q.push(*it);
                    vis[v]=true;//���ʵı�־
                }
            }
        }
        else{//�����˾Ͳ��ü�������ˣ�ֱ�Ӱ�����set�ù���
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
            inq[i]=true;//���͵ı�־
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
