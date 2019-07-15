#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,n,i,j,pos;
    string input;
    vector<string> mo;
    map<string,string> MAP;
    cin>>m>>n;
    getchar();
    i=m;
    while(m>0){
        getline(cin,input);
        mo.push_back(input);
        input.clear();
        m--;
    }

    while(n>0){
        input.clear();
        getline(cin,input);
        pos=input.find_first_of(" ");
        MAP[input.substr(0,pos)]=input.substr(pos+2,input.size()-pos-3);
        n--;
    }
    string now;//现在处理的一个串
    int BEGIN,END;
    string name;
    string ins;
    for(j=0;j<i;j++){
        now=mo[j];
        while(now.find("{{")!=string::npos){
            BEGIN=now.find("{{");
            END=now.find("}}");
            name=now.substr(BEGIN+3,END-BEGIN-4);
            ins="";
            ins=MAP[name];
            now.replace(BEGIN,END-BEGIN+2,ins);
        }
        cout<<now<<endl;
    }
    return 0;
}
