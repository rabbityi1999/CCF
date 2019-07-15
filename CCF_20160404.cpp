//#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
/*
ʱ��1h
�״��һ�������뱣֤�ҵ����Ž�������ͣ�˳����������DFS�����������������ǰʱ�䳬���˾Ͳ�Ӧ�ü������ˡ����Ѿ��ҵ������Ž��������ֹ���µ���ѭ��
�״����������뱣֤���������޵�ʱ�����ҵ����Ž⡿������·Ӧ����ͬʱ�ģ���Ӧ��д��if else���ֻ������һ·һֱû���ҵ����Ž�
ɵɵ�ؽ�begin��end��ɹؼ����ˣ�д�����ѹֱ���ͨ������
�Ժ��ύ֮ǰд��auto �����Լ��ı������õ����ĸ��汾��
10�ֵ�ԭ���Ǵ��볬ʱ�ˣ�����������д��
20�ּ�����һ����ά��������֦
�������֣����ǲ�Ӧ��������ѽ���ᳬʱ���ϣ�Ӧ���ù���
*/
using namespace std;
#define N 200 //�Ĵ��
int begin0[N]={0};
int end0[N]={0};
int pos[N][N]={0};
long long minTime=1000000000;
int n,m;
int visited[N+1][N+1][300+1]={0};
int safe(int i,int j,int time){
    if(pos[i][j]==0)
        return 1;
    else{
        if(time<begin0[pos[i][j]-1]||time>end0[pos[i][j]-1])
            return 1;
    }
    return 0;
}

void DFS(long long time,int i,int j){//ȥ��1�������������
    visited[i][j][time]=1;
    if(i==n-1&&j==m-1){
        if(time<minTime)
            minTime=time;
    }
    else{
        if(minTime>time+1){//����Ѿ��б�ĵ㵽�ˣ���ô�Ͳ������ˣ��������ѭ��
            if(i<n-1 && safe(i+1,j,time+1)&&visited[i+1][j][time+1]==0){//����
                //visited[i+1][j][time+1]=1;//��ʾ���ǹ���һ���ӵ������
                DFS(time+1,i+1,j);

            }
            if(j<n-1 && safe(i,j+1,time+1)&&visited[i][j+1][time+1]==0){//����
                //visited[i][j+1][time+1]=1;
                DFS(time+1,i,j+1);
            }
            if(0<i && safe(i-1,j,time+1)&&visited[i-1][j][time+1]==0){//����
                //visited[i-1][j][time+1]=1;
                DFS(time+1,i-1,j);
            }
            if(0<j && safe(i,j-1,time+1)&&visited[i][j-1][time+1]==0){//����
                //visited[i][j-1][time+1]=1;
                DFS(time+1,i,j-1);

            }
        }
    }
}
int main()
{
    auto d = 1;
    int t,i,r,c,a,b;
    cin>>n>>m>>t;
    for(i=0;i<t;i++){
        cin>>r>>c>>a>>b;//С��������������ת��
        pos[r-1][c-1]=i+1;//�������
        begin0[i]=a;
        end0[i]=b;
    }
    DFS(0,0,0);
    cout << minTime << endl;
    return 0;
}
