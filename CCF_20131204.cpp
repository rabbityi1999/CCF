#include <iostream>
/*
��������������ĵط������䶯̬�滮�㷨��������һ����ά���鱣��״̬�������˺����뵽���Լ�ɵɵ����ݹ�����ˣ�û�л�ͷ�룩
��Σ����뼼�ɷ��棬���Ƕ�ά���鵱��һ������ָ�붯̬������
ֵ��ע����״���ǣ����������long long �ͣ���Ȼ������Ϊ��������̫���gg
*/
using namespace std;

int main()
{
    long long mod = 1000000007;
    long long n;
    cin >> n;
    //ѧ�ŵ㣬�Ժ��ά�����������͵�Ҳ����ʵ�ֶ�̬���룬��ά����ı��ʾ���ָ���ָ�루����ָ��һά���飬����������ÿһ��Ԫ�ض���һ��һά���飬����ָͨ�룩
    long long **states=new long long*[n+1];
    for(long long i=0;i<n+1;i++)//�������ر��ʵ���˶�̬����
        states[i]=new long long[6];
    for(long long i=0;i<6;i++)//��ʼ����ֻ��Ҫ��ʼ����һ��
        states[0][i]=0;
        /*
        �����棬ÿ������λ��״̬����6�������
        * 0����ʣ013
16 16      * 1����ʣ13
17 17      * 2����ʣ01
18 18      * 3����ʣ3
19 19      * 4����ʣ1
20 20      * 5�����ޣ�ǰ�涼�õ���

        */
    for(long long i=1;i<=n;i++){
        long long j=i-1;
        states[i][0]=1;
        states[i][1]=(states[j][0]+states[j][1]*2)%mod;
        states[i][2]=(states[j][0]+states[j][2])%mod;
        states[i][3]=(states[j][1]+states[j][3]*2)%mod;
        states[i][4]=(states[j][1]+states[j][2]+states[j][4]*2)%mod;
        states[i][5]=(states[j][3]+states[j][4]+states[j][5]*2)%mod;
    }

    cout << states[n][5]<< endl;
    return 0;
}
