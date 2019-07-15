#include <iostream>
#include <string.h>
#include <stdio.h>
/*
题目超级简单，然而有个坑：
if(-1)会自动识别成1
*/
using namespace std;
int findstring(int flag,char *a,char *b){
    int len_a,len_b,i,j,k,ok=-1;
    char c[100]={0};
    char d[100]={0};
    for(i=0;i<strlen(a);i++){
        if(!flag)
            c[i]=tolower(a[i]);
        else
            c[i]=a[i];
    }
    for(i=0;i<strlen(b);i++){
        if(!flag)
            d[i]=tolower(b[i]);
        else
            d[i]=b[i];
    }
    //printf("inside !!!! %s    :   %s\n",c,d);
    for(i=0;i<(strlen(c)-strlen(d)+1);i++){
        ok=0;
        //printf("i=%d",i);
        if(c[i]==d[0]){
            ok=1;
            for(j=0,k=i;j<strlen(d);j++,k++){
               // printf("i=%d j=%d k=%d\n",i,j,k);
                if(c[k]==d[j]){
                //printf("c[k]==d[j] c[k]=%c  d[j]=%c\n",c[k],d[j]);
                    continue;
                }
                else{
                    //printf("c[k]!!!!=d[j] c[k]=%c  d[j]=%c\n",c[k],d[j]);
                    ok=0;
                    break;
                }
            }
            if(ok==1)//成功退出
                break;
        }
    }
    //printf("%d",ok);
    return ok;
}
int main()
{
    int yes[100]={0};
    char input[100][100]={0};
    char mod[100];
    int n,flag,i;
    gets(mod);
    scanf("%d",&flag);
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++){
        gets(input[i]);
        yes[i]=findstring(flag,input[i],mod);
    }
    for(i=0;i<n;i++){
        if(yes[i])
            printf("%s\n",input[i]);
    }
    return 0;
}
