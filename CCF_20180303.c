#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��������������ҷ������Լ�ɵ�Ƶ�һ�棬�˼�80�п���д��Ĵ��룬����Cд����150��û��д�ԣ��˷���̫��ʱ��
//������һ���ַ���һ���ַ�����ô�̰�ط�����������и����õ��㷨��������������д������Զ�޷�����������
//�õ��㷨�ǻ��ڸ�Ϊ�߼��Ĵ��뼼�ɵģ���Ҫ�Ȱ�C++���꣬�Ժ�CCF����Ŀȫ����C++��
int main()
{
    int i,j,k,p,n,m,x,q,fail=0,success=0;
    char rule[100][100]={0};
    char add[100][100];
    int name[100]={0},keeprule[100]={0},num[100]={0},result[100]={0};//��¼�����Ӧ������
    int begin[100][10];
    int end[100][10];//��¼��������ʼ���ͽ���λ��
    scanf("%d %d",&n,&m);
    getchar();//�����س�
    for(i=0;i<n;i++){//�������
        gets(rule[i]);
    }
    for(i=0;i<m;i++){//��������
        gets(add[i]);
    }
    for(i=0;i<m;i++){//��ʼ��m�����������һ�Ĵ���
        //printf("hahahhaah");
        //printf("get it!!");
        success=0;
        for(fail=0,success=0,p=0,k=0,j=0;j<n;j++){//ÿ������Ҫ����һ��
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
                if((rule[j][k]==' ')&&(k)&&(p)&&(add[i][p]=='\0')){//�Ѿ������ˣ��ɹ���
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
                else if(rule[j][k]=='<'){//��������˶Ի���
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
            q=strlen(rule[keeprule[i]])-(name[i]+1);//qΪ����ַ����ĳ���
                    for(k=0;k<q;k++){
                        printf("%c",rule[keeprule[i]][strlen(rule[keeprule[i]])-q+k]);//��������Ǹ���������
                    }
                    for(x=0;x<num[i];x++){//���������

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
