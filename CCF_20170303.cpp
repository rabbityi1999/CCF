#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/* 2:10~2:30 run this program using the console pauser or add your own getch, system("pause") or input loop */
void inside(string s){
		
}
void block(string line){
	if(line[0]=='#'){
		for(i=0,title=0;line[i]!=' ';i++);
		title=i/2;
		cout<<"<h"<<title<<">";
		inside(line.substr(i+1,line.length()-1-i));
		cout<<"</h"<<title<<">"<<endl;
	}
	else if(line[0]=='*'){
		while(line.length()!=0){
			
		}
		cout<<"<ul>"<<endl;
		for(i=0,title=0;line[i]!=' ';i++);
		inside(line.substr(i+1,line.length()-1-i));
		cout<<"</ul>"<<endl;
	}
	else if(line.length()==0){
		
	}
	else{
		
	}
}
int main(int argc, char** argv) {
	string  line;
	int i,j,k;
	int title;
	while(getline(cin,line)){
		block(string line);
	}
	return 0;
}
