 #include <bits/stdc++.h>
 using namespace std;
typedef long long LL;
struct node
{
      LL to, w, type;
};
vector<node>V[505];//ÿ����Ϊ��ʼ��㣬����һ��������һ��505������
bool vis[505];//vis�������Ƿ��Ѿ������ʹ���
LL dis[505], xl[505], n;//dis���鱣��ÿ���㵽Դ�ڵ�ľ���,xl��ʾ��xl[i]��֮ǰ�ж��ٳ��ȵ�С·Ҫ��
/*len��xl��������ã�����һ����Ϊ�����һ��
ͨ������������ݽṹ���Ϳ�����ԭ��ģ���Ͻ��иĽ���ʮ�����������
���ݽṹѡ����ˣ�һ������ͳɹ���һ���ˣ�����
���ﻹ�и��Լ�һֱ������ע�⵽�Ŀӵ�ѽ��int�ķ�Χ����2��15�η���long�ķ�Χ����2��31�η�
�������������long long�ͣ�����ͻ�����ˣ�������Щ������long��4/8 �ֽڣ�int��2/4�ֽڣ���ͳһò��vc6.0��֧�� long long��
*/void dij(LL s)
{
     LL i, j, k;

     for(i = 1; i <= n; i++)//��ÿ��node��ʼ��
     {
         vis[i] = 0;
         xl[i] = 0;
         dis[i] = 1e9;
     }

     dis[1] = 0;

     for(j = 1; j < n; j++)//��Ϊһ��n�����
     {
         LL min1 = 1e9;
         for(i = 1; i <= n; i++)
         {
             if(min1 >= dis[i] && !vis[i])
             {
                 min1 = dis[i];
                 k = i;
             }
         }//k��¼������Сdis���Ǹ�node�ı��

         vis[k] = 1;//����Ǳ�Ǳ�������
         for(i = 0; i < V[k].size(); i++)//�����dis��С�ĵ�ǰ��Ϊ��㣬��ʼ�������Һ��ʵ�node����ʼһ������node��
         {
             LL v = V[k][i].to, len = V[k][i].w, t = V[k][i].type;
             if(vis[v]) continue;
             if(t == 0)//����Ǵ�·
             {
                 if(dis[v] > dis[k] + len)
                 {
                     dis[v] = dis[k] + len;
                     xl[v] = 0;//��ʾ���ڵ���v�����·�����һ������С·��Ϊ֮�����׼��
                 }
             }
             else//�����С��
             {
                 if(!xl[k])//���֮ǰѡ����Ǵ�·��С·����һ��
                 {
                     if(dis[v] > dis[k] + len * len)
                     {
                         dis[v] = dis[k] + len * len;
                         xl[v] = len;//��ʾ���ڵ���v��·���г���Ϊlen��С��
                     }
                 }
                 else//���֮ǰѡ�����С·
                 {
                     LL len1 = (xl[k] + len) * (xl[k] + len) - xl[k] * xl[k];//֮����Ҫ��ȥ������ΪС·������ֵ�������ظ���
                     if(dis[v] > dis[k] + len1)
                     {
                         dis[v] = dis[k] + len1;
                         xl[v] = xl[k] + len;//��ʾ���ڵ���v��·���г���Ϊlen+xl[k]��С��
                     }
                 }
             }
         }
     }
}

int main()
{
    LL m, a, b;
    node q;
    scanf("%lld%lld", &n, &m);
    while(m--)
    {
        scanf("%lld%lld%lld%lld", &q.type, &a, &b, &q.w);
        q.to = b;
        V[a].push_back(q);
        q.to = a;
        V[b].push_back(q);//����һ���ܴ�Ҫע��ĵط�������ÿһ�������ıߣ�Ҫ�����������յ㶼������Ӧ�������ڣ���ô��������һ����ά���飩
    }
    dij(1);
    printf("%lld\n", dis[n]);
    return 0;
}
