#include <iostream>  
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
/*
���Ե�ʱ������visual 2012���Ǿ�û����dev c++
��visual 2012 ��  auto p = 1���﷨�ǳ����������Լ�ѡ����C++11��׼C0X���������û��ͨ��.....
���������ѡ��һ���Եı��뻷���ж�ô��Ҫ����ö���dev C++����Դ��������ϰ����Ҫ������Ŀ�.....;

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

