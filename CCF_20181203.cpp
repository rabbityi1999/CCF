/*
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <list>
using namespace std;



struct IP{
    unsigned int all;
    string addr[4];
    int len;
    string s2;
};
typedef struct IP ip_single;

string decToBin(int dec){
    char a[32]={0};
    string result;
    int temp = dec,j = 0;
    while(temp){
        a[j]=(temp%2)+'0';
        temp = temp/2;
        j++;
    }
    for(;j<32;j++)
        a[j]='0';
    result=a;
    return result;
}


void unif(string s,ip_single *ip){
    int k=0,sum=0,i,j,times=1,p,q,r;
    string save[4];
    string s0;
	istringstream into(s);
	char trans[40] = { 0 };
    s0=s;
    k=s.find('.');
    while(k!=-1){
        save[sum]=s.substr(0,k);
        ip->addr[sum]=save[sum];
        sum=sum+1;
        s=s.substr(k+1,s.length()-k-1);
        k=s.find('.');
    }

    //给len赋值
	k = s0.find('/');
    if(k!=-1){
        ip->len=atoi((s0.substr(k+1,s0.length()-k-1)).c_str());
    }
    else{
        ip->len=(sum+1)*8;
    }

	save[sum] = s.substr(0, k);
	ip->addr[sum] = save[sum];

	if (sum != 3) {
		for (p = sum+1; p < 4; p++)
			ip->addr[p] = "0";
	}
	ip->all = 0;

	sum = 3;
    do{
		r = atoi(ip->addr[sum].c_str());
        ip->all=ip->all+r*times;
        times=times*256;
        sum--;
    }while(sum>=0);
	//_itoa_s((ip->all),trans , 2);
    ip->s2= decToBin( ip->all);
	//ip->s2=trans;
}

bool compare(const ip_single &c,const ip_single &d){
    if (((c).all)!=((d).all)){
        return (((c).all)<((d).all));
    }
    else{
        return (((c).len)<((d).len));
    }
}

int equal(list<ip_single>::iterator a, list<ip_single>::iterator b) {

	if (a->len< b->len) {//从b当中找a
		//b->s2.find(a->s2.substr(0, a->len).c_str(), 0, a->le
		if (!strcmp(a->s2.substr(0,a->len).c_str(),b->s2.substr(0,a->len).c_str()))
			return 1;
	}
	else {//从a当中找b
		//a->s2.find(b->s2.substr(0, b->len).c_str(), 0, b->len)!=-1
		if (!strcmp(a->s2.substr(0,b->len).c_str(),b->s2.substr(0,b->len).c_str()))
			return -1;
	}
	return 0;
}
int unif(list<ip_single>::iterator a, list<ip_single>::iterator b) {
	int sum=0,i,j;
	if (a->len == b->len) {
		for (i = 0; i < a->len; i++) {
			if (a->s2[i] != b->s2[i])
				sum ++;
		}
	}
	if (sum==1)//最后一位其实不用管了
			return 1;

	return 0;
}
int main()
{
    int i,j,k,n,result;
    string get;
    cin>>n;
	list<ip_single> s;
    for(i=0;i<n;i++){
        ip_single now;
        cin>>get;
        unif(get,&now);
		s.push_back(now);
    }
	list<ip_single>::iterator it = s.begin();
	list<ip_single>::iterator it2;


    s.sort(compare);



	while (it!=s.end()) {
		it2 = it;
		it2++;
		while (it2 != s.end()&&it!=s.end()) {
			result = equal(it, it2);
			if (result == 1) {//说明it包含在了it2里面,需要删掉it，it2成为新的it
				it = it2;
				it2 = it;
				it2++;
			}
			else if(result ==-1){
				it2=s.erase(it2);
			}
			else {
				it2++;
			}
		}
		it++;
	}



	it = s.begin();
	while (it!=s.end()){
		it2 = it;
		it2++;
		if (it2 == s.end())break;//这里是个易错点！！！end就已经不可以调用了！！！！并不是最后一个！！！
		//&&( atoi((it->s2).c_str()+it->len) + atoi((it2->s2).c_str()+it2->len) == 1)
		//
		if ( unif(it,it2)){
			ip_single com;
			com.len = it->len - 1;
			com.s2 = it->s2;
			com.all = it->all;
			com.addr[0] = it->addr[0]; com.addr[1] = it->addr[1]; com.addr[2] = it->addr[2]; com.addr[3] = it->addr[3];
			s.insert(it,com);
			s.erase(it);
			it=s.erase(it2);
			it2 = it;
			it--;
			if (it != s.begin()) {
				it--;
				it2--;
			}
		}
		else {
			it++;
		}
	}


	it = s.begin();
	while (it != s.end()) {
		cout <<it->addr[0]<<'.'<<it->addr[1] << '.' <<it->addr[2]<<'.'<< it->addr[3]<<'/'<<it->len<< endl;
		it++;
	}

    return 0;
}
*/
// CCF_20171203.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

#define MINUTE 0
#define HOUR 1
#define DAY 2
#define MONTH 3
#define WEEK 4

int main(){
    int n,ct=0;

  ch=cin.get();
  while(ch!='\n'){
    cout<<ch;
    ct++;
    ch = cin.get();
  }
  cout<<ct<<endl;
  return 0;
}

