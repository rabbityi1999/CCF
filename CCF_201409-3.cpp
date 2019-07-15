#include <bits/stdc++.h>
using namespace std;

int main()
{
    string raw,input,save;
    raw=raw+'c';
    int BIG,i,n;
    cin>>raw;
    cin>>BIG>>n;
    if(!BIG){
        for(i=0;i<raw.size();i++)
            raw[i]=tolower(raw[i]);
    }
    while(n>0){
        cin>>input;
        save=input;
        if(!BIG){
            for(i=0;i<input.size();i++)
                input[i]=tolower(input[i]);
        }
        //cout<<input.find(raw)<<endl;
        if(input.find(raw)!=string::npos)
            cout<<save<<endl;
        n--;
    }
    return 0;
}
