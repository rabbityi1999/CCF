#include <iostream>
/*
本题做的最巧妙的地方就是其动态规划算法，构造了一个二维数组保存状态（正常人很难想到，自己傻傻地想递归想疯了，没有回头想）
其次，代码技巧方面，就是二维数组当作一个二次指针动态处理了
值得注意的易错点是，这里必须用long long 型，不然可能因为测试数据太大而gg
*/
using namespace std;

int main()
{
    long long mod = 1000000007;
    long long n;
    cin >> n;
    //学着点，以后二维数组这样整型的也可以实现动态申请，二维数组的本质就是指针的指针（看成指针一维数组，该数组里面每一个元素都是一个一维数组，即普通指针）
    long long **states=new long long*[n+1];
    for(long long i=0;i<n+1;i++)//这样子特别妙，实现了动态申请
        states[i]=new long long[6];
    for(long long i=0;i<6;i++)//初始化，只需要初始化第一个
        states[0][i]=0;
        /*
        这里面，每个数字位的状态都有6种情况：
        * 0－－剩013
16 16      * 1－－剩13
17 17      * 2－－剩01
18 18      * 3－－剩3
19 19      * 4－－剩1
20 20      * 5－－无，前面都用到了

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
