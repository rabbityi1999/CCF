#include <iostream>
#include <stack>

using namespace std;
//这里比较服气的是，复杂度竟然为O(n)，太棒了
const int N = 1000;
int h[N+1];

int main()
{
    int n, ans=0, area, temp;

    // 输入数据
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> h[i];
    h[n] = 0;

    // 计算最大矩形面积
    stack<int> s;
    for(int i=0; i<=n; i++) {
        if (s.empty() || h[s.top()] < h[i])
            s.push(i);
        else {
            temp = s.top();
            s.pop();            //弹出
            area = h[temp] * (s.empty() ? i : i - s.top() - 1);
            if (area > ans)
                ans = area;
            --i;
        }
    }

    // 输出结果
    cout << ans << endl;

    return 0;
}
