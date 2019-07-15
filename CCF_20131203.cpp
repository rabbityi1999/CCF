#include <iostream>
#include <stack>

using namespace std;
//����ȽϷ������ǣ����ӶȾ�ȻΪO(n)��̫����
const int N = 1000;
int h[N+1];

int main()
{
    int n, ans=0, area, temp;

    // ��������
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> h[i];
    h[n] = 0;

    // �������������
    stack<int> s;
    for(int i=0; i<=n; i++) {
        if (s.empty() || h[s.top()] < h[i])
            s.push(i);
        else {
            temp = s.top();
            s.pop();            //����
            area = h[temp] * (s.empty() ? i : i - s.top() - 1);
            if (area > ans)
                ans = area;
            --i;
        }
    }

    // ������
    cout << ans << endl;

    return 0;
}
