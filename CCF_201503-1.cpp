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
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    ll a,b,c,y1,y2,i;
    ll left,right;
    ll week;//a月1日是周几
    ll result;//代表最后的几号
    ll MAX;
    vector <int>  V;
    V.push_back(3);
    V.push_back(1);
    V.push_back(4);
    V.push_back(2);
    sort(V.begin(),V.end(),cmp);
    vector <int>::iterator it;
    for(it=V.begin();it!=V.end();it++)
        cout<<*it<<endl;
    /*
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
            /*
            if(a<10)
                cout<<"0";
            cout<<a<<"/";
            if(result<10)
                cout<<"0";
            cout<<result<<endl;
            cout<<setw(2)<<setfill('0')<<a<<"/";
            cout<<setw(2)<<setfill('0')<<result<<endl;
        }
        else{
            cout<<"none"<<endl;
        }
    }*/
    return 0;
}
