#include <bits/stdc++.h>
/* 1:15~2:47 自己2点差不多就写完了，因为变量命名的错误debug了好久
为什么我开始那样会错？
有没有更好用的replace函数和split？？查一下
查一下list，STL里面哪些是有序的，哪些是无序的？
*/
using namespace std;
vector<string> now;
vector<string> road;
vector<string> output;
void split(vector<string>& n,string s){
    int i;
    string save;
    for(i=0;i<s.size();i++){
        if(s[i]=='/')
            s[i]=' ';
    }
    istringstream in(s);
    while(in>>save){
        n.push_back(save);
    }
}

int main()
{
    int p,i,j;
    int juedui=0;
    string raw;
    string input;
    cin>>p>>input;
    raw=input;
    split(now,input);
    getchar();
    for(i=0,juedui=0;i<p;i++){
        if(getline(cin,input)!=false){
            road.clear();
            output.clear();
            if(input[0]=='/'){
                juedui=1;
            }
            else{
                output=now;
            }

            split(road,input);
            //分割后处理
            // cout<<road.size()<<endl;
            for(j=0;j<road.size();j++){;
                if(road[j]==".."){
                    if(road.size()!=0)
                        output.pop_back();
                }
                else if(road[j]=="."){}
                else{
                    output.push_back(road[j]);
                    //cout<<output[0]<<endl;
                }
            }
            //输出
            //cout<<output[0]<<endl;
            //cout<<output.empty()<<endl;
            if(output.empty())
                cout<<"/"<<endl;
            else{
                vector<string>::iterator it = output.begin();
                for(it = output.begin(); it != output.end(); ++it){
                    cout<<"/"<<*it;
                }
                cout<<endl;
            }
        }
        else{
            cout<<raw<<endl;
        }
    }
    return 0;
}
