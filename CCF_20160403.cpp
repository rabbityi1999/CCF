#include <bits/stdc++.h>
/* 1:15~2:47 �Լ�2�����д���ˣ���Ϊ���������Ĵ���debug�˺þ�
Ϊʲô�ҿ�ʼ�������
��û�и����õ�replace������split������һ��
��һ��list��STL������Щ������ģ���Щ������ģ�
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
            //�ָ����
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
            //���
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
