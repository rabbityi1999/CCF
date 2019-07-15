#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//从这个程序里面我发现了自己傻逼的一面，人家80行可以写完的代码，我用C写花了150还没有写对，浪费了太多时间
//不可以一个字符，一个字符地那么刻板地分析，你必须有个更好的算法！！！否则这样写程序永远无法进步！！！
//好的算法是基于更为高级的代码技巧的，我要先把C++看完，以后CCF的题目全部用C++！
int main()
{
    int i,j,k,p,n,m,x,q,fail=0,success=0;
    char rule[100][100]={0};
    char add[100][100];
    int name[100]={0},keeprule[100]={0},num[100]={0},result[100]={0};//记录规则对应的名字
    int begin[100][10];
    int end[100][10];//记录参数的起始，和结束位置
    scanf("%d %d",&n,&m);
    getchar();//消除回车
    for(i=0;i<n;i++){//读入规则
        gets(rule[i]);
    }
    for(i=0;i<m;i++){//读入输入
        gets(add[i]);
    }
    for(i=0;i<m;i++){//开始对m个输入进行逐一的处理
        //printf("hahahhaah");
        //printf("get it!!");
        success=0;
        for(fail=0,success=0,p=0,k=0,j=0;j<n;j++){//每个规则都要尝试一遍
            fail=0;
            p=0;
            k=0;
            //printf("this is %d times try\n",j);
            if(success)
                break;
            num[i]=0;
            while((!success)&&(!fail)){
               // printf("get in first while 1");
                //printf("rule[j][k]=%c,add[i][p]=%c, ok j is %d,k is %d,p is %d  \n",rule[j][k],add[i][p],j,k,p);
                if((rule[j][k]==' ')&&(k)&&(p)&&(add[i][p]=='\0')){//已经到顶了，成功了
                    //printf("rule[j][k]==" "hhhhhhhhhhhhh ok\n");
                    name[i]=k;
                    keeprule[i]=j;
                    success=1;
                    result[i]=1;
                }
                else if(rule[j][k]==add[i][p]){
                  //  printf("rule[j][k]==add[i][p] ok j is %d,p is %d\n",j,p);
                    k++;
                    p++;
                    continue;
                }
                else if(rule[j][k]=='<'){//进入参数核对环节
                    //printf("we can check the argv, j is %d,p is %d\n",j,p);
                    begin[i][num[i]]=p;
                    if((rule[j][k]=='<')&&(rule[j][k+1]=='i')&&(rule[j][k+2]=='n')&&(rule[j][k+3]=='t')){
                        k=k+6;
                        while(1){
                            if((add[i][p]=='/')||(add[i][p]==' ')){
                                end[i][num[i]]=p-1;
                                p++;
                                num[i]++;
                               // printf("success check\n");
                                break;
                            }
                            else if((add[i][p]>='0')&&(add[i][p]<='9')){
                               // printf("success check\n");
                                p++;
                            }
                            else{
                               // printf("not a number\n");
                                fail=1;
                                break;
                            }
                        }
                    }
                    else if((rule[j][k]=='<')&&(rule[j][k+1]=='s')&&(rule[j][k+2]=='t')&&(rule[j][k+3]=='r')){
                        k=k+6;
                        while(1){
                            if((add[i][p]=='/')||(add[i][p]==' ')){
                                end[i][num[i]]=p-1;
                                num[i]++;
                                p++;
                                break;
                            }
                            else if(((add[i][p]>='0')&&(add[i][p]<='9'))||((add[i][p]>='A')&&(add[i][p]<='Z'))||((add[i][p]>='a')&&(add[i][p]<='z'))||(add[i][p]=='-')||(add[i][p]=='_')||(add[i][p]=='.')||(add[i][p]=='/')){
                                p++;
                            }
                            else{
                                fail=1;
                                break;
                            }
                        }
                    }
                    else{
                        k=k+6;
                        while(1){
                            if(add[i][p]=='\0'){
                                end[i][num[i]]=p-1;
                                num[i]++;
                                p++;
                                break;
                            }
                            else if(((add[i][p]>='0')&&(add[i][p]<='9'))||((add[i][p]>='A')&&(add[i][p]<='Z'))||((add[i][p]>='a')&&(add[i][p]<='z'))||(add[i][p]=='-')||(add[i][p]=='_')||(add[i][p]=='.')||(add[i][p]=='/')){
                                //printf("inside  rule[j][k]=%c,add[i][p]=%c, ok j is %d,k is %d,p is %d  \n",rule[j][k],add[i][p],j,k,p);
                                p++;
                            }
                            else{
                                //printf("get in fail");
                                fail=1;
                                break;
                            }
                        }
                    }
                }
                else{
                    fail=1;
                    break;
                }
            }
        }
        if(fail){
            result[i]=0;
        }
    }
    for(i=0;i<m;i++){
        if(result[i]){
           // printf("keeprule id %d num[i] is%d",keeprule[i],num[i]);
            q=strlen(rule[keeprule[i]])-(name[i]+1);//q为输出字符串的长度
                    for(k=0;k<q;k++){
                        printf("%c",rule[keeprule[i]][strlen(rule[keeprule[i]])-q+k]);//先输出了那个规则名字
                    }
                    for(x=0;x<num[i];x++){//将参数输出

                        printf(" ");
                        q=end[i][x]-begin[i][x]+1;
                        for(k=0;k<q;k++){
                            printf("%c",add[i][begin[i][x]+k]);
                        }

                    }
                    printf("\n");
        }
        else{
            printf("404\n");
        }
    }
    return 0;
}
