#include <iostream>

using namespace std;

int main()
{
    long long N;
    long long left = 0;
    long long sub=0,temp,oldnum,dropnum=0;
    long long  i,j,times,threenum=0;
    bool drop[5000] = {false};
    bool ifdrop = false;
    cin >> N;

    for(i=1;i<=N;i++){
        cin>>times>>oldnum;
        for(ifdrop = false,j=0,sub=0;j<times-1;j++){
            cin>>temp;
            if(temp>0){
                    if(temp<oldnum + sub){
                        ifdrop = true;
                        dropnum++;
                    }
                    sub = 0;
                    oldnum = temp;
            }else{
                sub = sub + temp;
            }
        }
        left = left + oldnum +sub;
        drop[i] = ifdrop;
    }
    if(drop[N]&&drop[2]&&drop[1]){
        threenum++;
    }
    if(drop[N]&&drop[N-1]&&drop[1]){
        threenum++;
    }
    for(i=2;i<N;i++){
        if(drop[i]&&drop[i-1]&&drop[i+1]){
            threenum++;
        }
    }
    cout<<left<<" "<<dropnum<<" "<<threenum<<endl;

    return 0;
}
