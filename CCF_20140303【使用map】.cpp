#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int ifsame(char a,char *mod){
    int k=-1;
    for(int i=0;i<strlen(mod);i++){
        if(a==mod[i])
        {
            if(mod[i+1]==':')
                k=2;
            else
                k=1;
            break;
        }
    }
    return k;
}

int dect(int i,char *str){//���ز�������
    int length=0;
    for(;i<strlen(str);i++){
            if(str[i]==' '){//ע��ǿյ�����
                break;
            }
            else if(((str[i]>='a')&&(str[i]<='z'))||(((str[i]-'0')>=0)&&((str[i]-'0')<=9))||(str[i]=='-')){
                length++;
            }
            else{
                length=-1;
            }
    }
    return length;
}

/*void backmove(int i,int index,int num,char *str){//��i��ʼ��ƫ��indexλ���ַ�����ԭ������λnumλ

}
*/
int main()
{
    int j,n,p,i,k,d;
    char mod[256]={0};
    char input[20][256]={0};
    char output[20][256]={0};
    int num[20]={0};
    int argv[20][150]={0};//�����������
    //����
    gets(mod);
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        //input[i]=new char[256];
        gets(input[i]);
    }

    for(int i=0;i<n;i++){
        //output[i]=new char[256];//��Ҫ��ʼ��Ϊ\0
        for(int j=0;j<strlen(input[i]);j++){
            if((input[i][j]==' ')&&(input[i][j+1]=='-')){
                if(ifsame(input[i][j+2],mod)<0){//����ǷǷ������ֱ�Ӳ���Ҫ������ȡ��
                    break;
                }
                else if(ifsame(input[i][j+2],mod)==1){//�����һ�����
                    int same=0;
                    for(k=0;k<num[i];k++){
                        if(output[i][k]==input[i][j+2]){//����ظ��ˣ����ùܣ�����
                            same=1;
                            break;
                        }
                    }
                    if(!same){//���û���ظ�����Ҫ����output
                        output[i][num[i]]=' ';
                        output[i][num[i]+1]='-';
                        output[i][num[i]+2]=input[i][j+2];
                        num[i]=num[i]+3;
                    }
                }
                else if(ifsame(input[i][j+2],mod)==2){//������Ҳ��������
                  //  printf("else if(ifsame(input[i][j+2],mod)==2)\n");
                    if(dect(j+4,input[i])<0){//���������Ĳ��������Խ���
                  //  printf("if(dect(j+4,input[i])<0){\n");
                        break;
                    }
                    else if(dect(j+4,input[i])>0){//�������Ĳ���
                       // printf("if(dect(j+4,input[i])>0){\n");
                        int same=0;
                        for(k=0;k<num[i];k++){
                            if(output[i][k]==input[i][j+2]){//����ظ��ˣ����ùܣ�����
                                same=1;
                                break;
                            }
                        }
                        if(!same){//���û���ظ�����Ҫ����output������Ҳ��Ҫ����
                            output[i][num[i]++]=' ';
                            output[i][num[i]++]='-';
                            output[i][num[i]++]=input[i][j+2];
                            output[i][num[i]++]=' ';
                            j=j+4;
                            d=dect(j,input[i]);
                            argv[i][(int)(input[i][j])]=d;
                           // printf("%d\n",d);
                            for(p=0;p<d;p++){
                            //    printf("%d%c\n",p,input[i][j]);
                                output[i][num[i]++]=input[i][j++];
                            }
                            j--;
                        }
                        else if(same){//����ظ��ˣ�just��������,�������ѵ㣬�㲻��Ҫȫ���i��ʼ����
                           // printf("same\n");

                            j=j+4;
                            d=dect(j,input[i]);//�µĲ�������
                           //  printf("%d\n",d);
                            argv[i][(int)(input[i][j])];//�ɵĲ�������
                           //  /printf("%d\n",argv[i][(int)(input[i][j])]);
                            //backmove(int i,,int num,,output[i]);
                            k=k+2;

                            output[i] = output[i].replace(k,argv[i][(int)(input[i][j])],input[i],j,d);
                            /*for(p=0;p<d;p++){
                                output[i][k++]=input[i][j++];
                            }
                            j--;*/
                        }
                    }
            }
        }
            else if((input[i][j]==' ')&&(input[i][j+1]!='-')){
                //printf("(input[i][j]==' ')&&(input[i][j+1]!='-')break;\n");
                break;
            }
        }
    }
    for(i=0;i<n;i++){
        j=i+1;
        printf("Case %d:%s\n",j,output[i]);
    }
    return 0;
}
