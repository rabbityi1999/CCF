#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set> 
#include <queue>
#include <vector>
using namespace std;
int n,k,p;
//nowK��ǰ��ѡ���ĸ��� 
 // sumP��ǰ��pƽ����
 // sumf��ǰ������ƽ����
 // s����ǰ��ѡ���� 
 //��ǰ���ڴ���ĵ�index����
vector<int> ans;  
int sum_ans=-1;
bool cmp(int& x,int& y){
	return x>y;
}
void DFS(int index,int nowK, int sumP,int sumf,vector<int> s){
	if(nowK == k && sumP==n ){
		if(sumf>sum_ans){
			sum_ans=sumf;
			ans=s;
		}
		else if(sumf==sum_ans){
        	 sort(s.begin(),s.end(),cmp);	
			 if(s>ans){
			 	ans=s;
			 }		
		}
	}
	if(index>n || nowK>k ||sumP>n){
		return;
	}
	
	//ѡ�µ�index����,����index���ظ� 
	s.push_back(index);
	DFS(index,nowK+1,sumP+pow(index,p),sumf+index,s); 
	//��ѡ�µ�index����
	s.erase(find(s.begin(),s.end(),index));
	DFS(index+1,nowK,sumP,sumf,s); 
}

int main(){
	vector<int> s;
	s.push_back(1);
	cin>>n>>k>>p;
	DFS(1,1,1,1,s);
	if(sum_ans==-1)
 	    cout<<"Impossible";
 	else{
 		vector<int>::iterator it;
 		cout<<n;
		for(it=s.begin();it<s.end();it++){
			if(it==s.begin()){
				cout<<" = ";
			}
			else{
				cout<<" + ";
			}
			cout<<*it<<"^"<<p;
		} 
	 }
 	cout<<endl; 
	return 0;
}


