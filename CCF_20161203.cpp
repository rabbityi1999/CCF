#include <iostream>  
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
/*
考试的时候发现有visual 2012于是就没有用dev c++
在visual 2012 上  auto p = 1的语法是成立的于是自己选择了C++11标准C0X，结果编译没有通过.....
这告诉我们选对一个对的编译环境有多么重要，最好多用dev C++这个自带的软件练习，不要吃软件的亏.....;

*/
typedef long long LL;
using namespace std;
#define N 100000

LL array[N]={0};

int main(){
    LL i,j,n,read,MAX,MIN;
    double mid;
    double a,b;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>array[i];
    }
    //sort(array,array+n);
    MAX=max(array[n-1],array[0]);
    MIN=min(array[n-1],array[0]);
    cout<<MAX<<" ";
    if(n%2==0){
        if(((array[n/2]+array[n/2-1])%2)==0){
            cout<<(array[n/2]+array[n/2-1])/2;
        }
        else{
            a=(double)array[n/2];
            b=(double)array[n/2-1];
            mid=(double)(a+b)/2;
            printf("%0.1f",mid);
        }
    }else{
        cout<<array[(n-1)/2];
    }
    cout<<" "<<MIN<<endl;
    return 0;
}

