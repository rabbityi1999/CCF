#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000
int M[N][N]={0};
int main()
{
    ll n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>M[i][j];
        }
    }
    for(j=m-1;j>=0;j--){
        for(i=0;i<n;i++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000

struct num{
    ll value;
    ll time;
    //num(ll x,ll y):value(x),time(y) {}
};
//ll num[N]={0};
bool cmp(const num& x,const num& y){
    if(x.time==y.time){
        return x.value<y.value;
    }
    return x.time>y.time;
}

int main()
{
    ll n,i,now;
    num in;
    map<int ,num> MAP;
    map<int ,num>::iterator it;
    vector<num> V;
    V.clear();
    MAP.clear();
    cin>>n;

    for(i=0;i<n;i++){
        cin>>now;
        if(MAP.find(now)==MAP.end()){
                in.value=now;
        in.time=1;
            MAP[now]=in;
        }
        else{
            MAP[now].time++;
        }
    }
    for(it=MAP.begin();it!=MAP.end();it++){
        V.push_back(it->second);
    }
    sort(V.begin(),V.end(),cmp);
    for(i=0;i<V.size();i++){
        cout<<V[i].value<<" "<<V[i].time<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
    int MON[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int runnian(ll year){
    if(year%400==0||(year%4==0&&year%100!=0))
        return 1;
    else
        return 0;
}
int zhouji(ll year,ll month){//计算该年的a月1号是周几
    ll i,sum=0;
    for(i=1850;i<year;i++){
        if(runnian(i)==1)
            sum=sum+366;
        else
            sum=sum+365;
    }
    for(i=1;i<month;i++){
        sum+=MON[i];
    }
    if(runnian(year)==1&&month>2)
        sum+=1;
    return ((sum+1)%7+1);
}

int main()
{
    ll a,b,c,y1,y2,i;
    ll left,right;
    ll week;//a月1日是周几
    ll result;//代表最后的几号
    ll MAX;
    cin>>a>>b>>c>>y1>>y2;
    left=min(y1,y2);
    right=max(y1,y2);

    for(i=left;i<=right;i++){
        week=zhouji(i,a);
        if(week==c)
            result=(b-1)*7+1;
        else if(c<week){
            result=(b-1)*7+1+7-(week-c);
        }
        else{
            result=(b-1)*7+1+(c-week);
        }
        MAX = MON[a];
        if(runnian(i)==1)MAX++;
        if(result>0&&result<=MAX){
            cout<<i<<"/";//年
            if(a<10)
                cout<<"0";
            cout<<a<<"/";
            if(result<10)
                cout<<"0";
            cout<<result<<endl;
        }
        else{
            cout<<"none"<<endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000//记得改
class cmp{
public:
    bool operator()(const int& s1,const int& s2){
            return s1>s2;
    }
};
set<int,cmp > father[N];
ll layer[N]={0};//每个点的层次
bool isRoot[N];
vector<int> isleaf;
void Union(int a,int i){//a是i的直接father
    layer[i]=layer[a]+1;
    set<int>::iterator it;
    //那么a的所有father也是i的所有father
    for(it=father[a].begin();it!=father[a].end();it++){
        father[i].insert(*it);
    }
    father[i].insert(a);
}

int main()
{
    ll n,m;
    ll i,j,a,b,result=0;
    cin>>n>>m;
    layer[1]=0;
    for(i=1;i<=n+m;i++){
        //father[i].insert(i);
        isRoot[i]=false;
    }
    for(i=2;i<=n;i++){
        cin>>a;
        Union(a,i);//那么a是i的father
        isRoot[a]=true;
    }
    for(i=n+1;i<=n+m;i++){
        cin>>a;
        Union(a,i);
        isRoot[a]=true;
    }
    for(i=1;i<=n+m;i++)
        result=max(layer[i],result);

    for(i=1;i<=n+m;i++){
        if(isRoot[i]!=true)//说明是叶子结点
        {
            isleaf.push_back(i);
        }
    }
    vector<int>::iterator it;
    vector<int>::iterator it2;
    set<int>::iterator root;
    //遍历所有的叶的根结点
    //从大向小，第一个相同的

    for(it=isleaf.begin();it!=isleaf.end();it++){
        for(it2=it;it2!=isleaf.end();it2++){
            for(root=father[*it].begin();root!=father[*it].end();root++){//root遍历it的father集和
                //找到了
                if(father[*it2].find(*root)!=father[*it2].end()){//在it2中找到了一样的号码的
                    //这时*root就是那个father
                    result=max(result,layer[*it]+layer[*it2]-2*layer[*root]);
                    break;
                }
            }
        }
    }
    cout<<result<<endl;
    return 0;
}
