#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
/*
1��ÿ������ĵ��ַ���ͬ�����ߵķ���Ҳ��ͬ�������Ҫ��һ���������ݵ�ǰ�����ַ�ȷ�����ߵķ���

2����������1��ͨ������㿪ʼBFS����һ������v1��¼���ߵ��ķ�������һ����ά��able[x1][y1][x2][y2]�����ʾ�ܴ�(x1,y1)�ߵ�(x2,y2)����һ����Ҫ�õ���

3����������2���������ֱ�����ǱȽ����ѵģ������ת��ȥ���ĳ����������ܹ������յ�ķ�����Զ��Ի�Ƚϼ򵥡�

���յ㿪ʼBFS������able���飬��v2�����¼�ܹ������յ�ķ�����ôʣ�µķ�����ǲ��ܵ����յ���ˡ�

4��ͳ��v1�������û�б�v2��ǵķ��������õ��𰸡�
*/
using namespace std;

struct P{
    int x,y;
};

char Map[55][55];
int mov[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
bool able[55][55][55][55],v1[55][55],v2[55][55];

void get(P a,int &st,int &ed){
    if(Map[a.x][a.y]=='-') st=2,ed=4;
    else if(Map[a.x][a.y]=='|') st=0,ed=2;
    else if(Map[a.x][a.y]=='.') st=0,ed=1;
    else st=0,ed=4;
}
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i) scanf("%s",Map[i]);//����ͼ��侫�ɣ�ʡ���룬ͨ���ַ�������ʽ���룬�ǳ���ӱ
    queue<P> q;//һ��Ҫ�����STL��������õ�ģ�壬�ṹ����ĺ��ǻ��°빦����
    P p,e;
    for(i=0;i<n;++i)
    for(j=0;j<m;++j){
        if(Map[i][j]=='S'){
            p.x=i,p.y=j;
            q.push(p);
        }
        else if(Map[i][j]=='T'){
            e.x=i,e.y=j;
        }
    }
    memset(v1,0,sizeof(v1));//��memset�����ʼ��������forѭ�������ʼ��ǿ����
    memset(v2,0,sizeof(v2));
    memset(able,0,sizeof(able));
    v1[p.x][p.y]=1;
    while(!q.empty()){//һֱ������qΪ�գ�q����ʼ��һ�����
        p=q.front();q.pop();
        P tem=p;
        int st,ed;
        get(p,st,ed);
        for(i=st;i<ed;++i){//BFS��˼�룺���ڴӶ���pop�����ĵ㣬���������������һ�飬����
            tem.x=p.x+mov[i][0];
            tem.y=p.y+mov[i][1];
            if(tem.x>=0&&tem.y>=0&&tem.x<n&&tem.y<m&&Map[tem.x][tem.y]!='#'){
                able[p.x][p.y][tem.x][tem.y]=1;
                if(!v1[tem.x][tem.y]){
                    v1[tem.x][tem.y]=1;
                    q.push(tem);//�������ˣ�����ĵ�������ջ
                }
            }
        }
    }
    if(!v1[e.x][e.y]) {puts("I'm stuck!");return 0;}//��ҳ�ʼ״̬�Ͳ��ɴ��յ�
    int ans=0;
    q.push(e);
    v2[e.x][e.y]=1;
    while(!q.empty()){
        p=q.front();q.pop();
        P tem=p;
        for(i=0;i<4;++i){
            tem.x=p.x+mov[i][0];//able������ĺ���Ҫѽ����������able����.able����Ҫ�Ϳɴ��λ�ö�Ӧ����Ҫ���յ�ɴBFS�������ĸ����򣩣���Ҫ�ɴ��յ㣬��Ӧ
            tem.y=p.y+mov[i][1];
            if(tem.x>=0&&tem.y>=0&&tem.x<n&&tem.y<m&&Map[tem.x][tem.y]!='#'&&able[tem.x][tem.y][p.x][p.y]&&!v2[tem.x][tem.y]){
                v2[tem.x][tem.y]=1;
                q.push(tem);
            }
        }
    }
    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
            if(v1[i][j]&&!v2[i][j]) ++ans;
    printf("%d\n",ans);
    return 0;
}
