//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define HAS 0
#define NOT 1
//3:48~5:04
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct RIGHTS{
	int kind;
	int level;
	string name;
//	RIGHTS(int vv1,int vv2,string c):kind(vv1),level(vv2),name(c){}
};
struct ROLE{
	vector<RIGHTS> rights;
//	ROLE(vector<RIGHTS> in):rights(in){}
};
struct USER{
	vector<ROLE> roles;
//	USER(vector<ROLE> role):roles(role){}
};

map<string,ROLE> roleMap;
map<string,RIGHTS> rightMap;
map<string,USER> userMap;
int main(int argc, char** argv) {
	int n,i,j;
	int level;
	int num,find;
	string s;
	string user_name;
	string name;
	vector<RIGHTS> rig;
	vector<ROLE> rol;
    string name_r;
	cin>>n;
	while(n>0){
		getline(cin, s);
		struct RIGHTS newone;
		if(s.find(":")!=-1){
            s.replace(s.find(":"),1," ");
            istringstream in(s);
            in>>name>>level;
            newone.kind=HAS;
            newone.level=level;
            newone.name=name;
            rightMap[name]=newone;
		}
		else{
            name = s;
            newone.kind=NOT;
            newone.level=0;
            newone.name=name;
            rightMap[name]=newone;
		}
		n--;
	}
	cin>>n;
	while(n>0){
        cin>>name>>num;
        rig.clear();
        while(num>0){
            cin>>s;
            struct RIGHTS newone;
            if(s.find(":")!=-1){
                s.replace(s.find(":"),1," ");
                istringstream in(s);
                in>>name_r>>level;
                newone.kind=HAS;
                newone.level=level;
                newone.name=name_r;
                rig.push_back(newone);
            }
            else{
            	newone.kind=NOT;
                newone.level=0;
                newone.name=s;
                rig.push_back(newone);
            }
            struct ROLE newrole;
            newrole.rights = rig;
            roleMap[name]=newrole;
            num--;
        }
        n--;
	}

	cin>>n;
	while(n>0){
        cin>>name>>num;
        rol.clear();
        while(num>0){
            cin>>name_r;//角色
            rol.push_back(roleMap[name_r]);
        }
        struct USER newuser;
        newuser.roles=rol;
        userMap[name]=newuser;
        n--;
	}
	cin>>n;
	while(n>0){
        cin>>user_name>>s;
        if(s.find(":")!=-1){
            s.replace(s.find(":"),1," ");
            istringstream in(s);
            in>>name>>level;
        }
        else{
            level = -1;
            name=s;
        }
        //遍历用户角色的权限们
        for(find=0,i=0;i<userMap[user_name].roles.size();i++){
            for(j=0;j<userMap[user_name].roles[i].rights.size();j++){
                if(userMap[user_name].roles[i].rights[j].name==name){
                    if(rightMap[name].kind==NOT){
                        find = 1;
                        cout<<"true"<<endl;
                        break;
                    }
                    else if(rightMap[name].kind==HAS){
                        if(level==-1){
                            find=1;
                            cout<<userMap[user_name].roles[i].rights[j].level<<endl;
                            break;
                        }
                        else{
                            if(userMap[user_name].roles[i].rights[j].level>=level){
                                cout<<"true"<<endl;
                                find=1;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(find==0){
            cout<<"false"<<endl;
        }
        n--;
	}
	return 0;
}
