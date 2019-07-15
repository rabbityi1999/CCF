/* CCF201609-3 炉石传说 */

#include <iostream>
#include <vector>
#include <string>

#define OPONENT 1-player

using namespace std;

// 红黑双方，红先黑后
const int RED = 0;
const int BLACK = 1;

// 状态包括生命值和攻击力
struct status {
    int life, power;
    status(int l, int a){life = l; power = a;}
};

// 变量v用于存储英雄和随从的状态，v[0]为红方，v[1]为黑方
// 向量v[RED]和v[BLACK]中分别存储双方的英雄和随从的状态
// v[RED][0]存储红方英雄的状态，v[RED][1]-v[RED][7]存储随从的状态
vector<status> v[2];//v(2)就是一个大小为2的一维数组了
//这个就相当于二个动态结构数组，每个都可以动态增长，就相当于是二维的了；最大的优点是动态的，而且还有很多好用的函数！

int main()
{
    int n, player=RED;
    string action;
    int position, attack, health;
    int attacker, defender;

    // 变量初始化：英雄在向量v中的位置为０
    v[RED].push_back(status(30, 0));
    v[BLACK].push_back(status(30, 0));

    // 输入数据：命令数量n
    cin >> n;

    // 输入并且处理n个命令
    while(n--) {
        cin >> action;
        if(action == "summon") {
            cin >> position >> attack >> health;

            v[player].insert(v[player].begin() + position, status(health, attack));
        } else if(action == "attack") {
            cin >> attacker >> defender;

            // 当随从攻击时，攻击方和被攻击方会同时对彼此造成等同于自己攻击力的伤害。
            // 受到伤害的角色的生命值将会减少，数值等同于受到的伤害。
            v[player][attacker].life -= v[OPONENT][defender].power;
            v[OPONENT][defender].life -= v[player][attacker].power;

            // 攻击方（随从）生命结束则移除
            if(v[player][attacker].life <= 0)
                v[player].erase(v[player].begin() + attacker);

            // 防御方的随从生命结束则移除
            if(defender != 0 && v[OPONENT][defender].life <= 0)
                v[OPONENT].erase(v[OPONENT].begin() + defender);

        } else if(action == "end") {
            player = OPONENT;
        }
    }

    // 输出结果
    // 第１行
    if(v[RED][0].life <=0)
        cout << -1 << endl;
    else if(v[BLACK][0].life <=0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    // 第２行
    cout << v[RED][0].life << endl;
    // 第３行
    cout << v[RED].size() - 1;
    for(int i=1; i<(int)v[RED].size(); i++)
        cout << " " << v[RED][i].life;
    cout << endl;
    // 第４行
    cout << v[BLACK][0].life << endl;
    // 第5行
    cout << v[BLACK].size() - 1;
    for(int i=1; i<(int)v[BLACK].size(); i++)
        cout << " " << v[BLACK][i].life;
    cout << endl;

    return 0;
}
