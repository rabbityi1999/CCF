#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	long long n,max=-1;
	long long i,j;
	long long first,second;
	scanf("%d",&n);
	scanf("%d",&first);
	for(i=1;i<n;i++){
		scanf("%d",&second);
		if(first>second){
			j=first-second;
		}
		else
		{
			j=second-first;
		}
		if(j>max)
			max=j;
		first=second;
	}
	printf("%d",max);
	return 0;
}
