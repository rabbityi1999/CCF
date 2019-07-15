/* CCF201609-3 ¯ʯ��˵ */

#include <iostream>
#include <vector>
#include <string>

#define OPONENT 1-player

using namespace std;

// ���˫�������Ⱥں�
const int RED = 0;
const int BLACK = 1;

// ״̬��������ֵ�͹�����
struct status {
    int life, power;
    status(int l, int a){life = l; power = a;}
};

// ����v���ڴ洢Ӣ�ۺ���ӵ�״̬��v[0]Ϊ�췽��v[1]Ϊ�ڷ�
// ����v[RED]��v[BLACK]�зֱ�洢˫����Ӣ�ۺ���ӵ�״̬
// v[RED][0]�洢�췽Ӣ�۵�״̬��v[RED][1]-v[RED][7]�洢��ӵ�״̬
vector<status> v[2];//v(2)����һ����СΪ2��һά������
//������൱�ڶ�����̬�ṹ���飬ÿ�������Զ�̬���������൱���Ƕ�ά���ˣ������ŵ��Ƕ�̬�ģ����һ��кܶ���õĺ�����

int main()
{
    int n, player=RED;
    string action;
    int position, attack, health;
    int attacker, defender;

    // ������ʼ����Ӣ��������v�е�λ��Ϊ��
    v[RED].push_back(status(30, 0));
    v[BLACK].push_back(status(30, 0));

    // �������ݣ���������n
    cin >> n;

    // ���벢�Ҵ���n������
    while(n--) {
        cin >> action;
        if(action == "summon") {
            cin >> position >> attack >> health;

            v[player].insert(v[player].begin() + position, status(health, attack));
        } else if(action == "attack") {
            cin >> attacker >> defender;

            // ����ӹ���ʱ���������ͱ���������ͬʱ�Ա˴���ɵ�ͬ���Լ����������˺���
            // �ܵ��˺��Ľ�ɫ������ֵ������٣���ֵ��ͬ���ܵ����˺���
            v[player][attacker].life -= v[OPONENT][defender].power;
            v[OPONENT][defender].life -= v[player][attacker].power;

            // ����������ӣ������������Ƴ�
            if(v[player][attacker].life <= 0)
                v[player].erase(v[player].begin() + attacker);

            // ����������������������Ƴ�
            if(defender != 0 && v[OPONENT][defender].life <= 0)
                v[OPONENT].erase(v[OPONENT].begin() + defender);

        } else if(action == "end") {
            player = OPONENT;
        }
    }

    // ������
    // �ڣ���
    if(v[RED][0].life <=0)
        cout << -1 << endl;
    else if(v[BLACK][0].life <=0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    // �ڣ���
    cout << v[RED][0].life << endl;
    // �ڣ���
    cout << v[RED].size() - 1;
    for(int i=1; i<(int)v[RED].size(); i++)
        cout << " " << v[RED][i].life;
    cout << endl;
    // �ڣ���
    cout << v[BLACK][0].life << endl;
    // ��5��
    cout << v[BLACK].size() - 1;
    for(int i=1; i<(int)v[BLACK].size(); i++)
        cout << " " << v[BLACK][i].life;
    cout << endl;

    return 0;
}
