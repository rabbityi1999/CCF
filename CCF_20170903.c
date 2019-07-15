/* CCF201709-3 JSON查询 */
 
#include <iostream>
#include <string>
#include <map>
 
using namespace std;
 
int n, m;
string s, key;
map<string, string> json;
int state;
 
void handle(string& s)
{
    for(int i = 0; s[i]; i++) {
        if(s[i] == '{'){
            if(state == 0){
                key = "";
            } 
			else {
                json[key] = "OBJECT";
            }
            state = 1;//一旦读入了‘{’之后,状态就变成了1
        } 
		else if(s[i] == '}'){
            int j;
            for(j = (int)key.size() - 1; j >= 0; j--) {
                if(key[j] == '.')
                    break;
            }
            if(j >= 0)
                key = key.substr(0, j);//取子字符串
            else
                key = "";
        } 
		if(s[i] == ':'){
            state = 2;
        } 
		if(s[i] == ','){
            state = 1;//进入下一组需要考虑的
        } 
		if(s[i] == '"'){  // 双引号
            string tmp;
            for(i++; s[i]; i++) {
                if(s[i] == '\\')//如果说s[i]=='\\'
                    tmp += s[++i];
                else if(s[i] == '"')    // 双引号
                    break;
                else
                    tmp += s[i];
            }
            if(state == 1) {
                if(key == "")
                    key = tmp;
                else
                    key += '.' + tmp;
                state = 2;
            } 
			else if(state == 2) {
                json[key] = "STRING " + tmp;
                int j;
                for(j = (int)key.size() - 1; j >= 0; j--) {
                    if(key[j] == '.')
                        break;
                }
                if(j >= 0)
                    key = key.substr(0, j);
                else
                    key = "";
                state = 1;
            }
        }
    }
}
 
int main()
{
    cin >> n >> m;
    getline(cin, s);
 
    state = 0;
    while(n--) {
        getline(cin, s);
        handle(s);
    }
 
    while(m--) {
        cin >> s;
        cout << (json[s] == "" ? "NOTEXIST" : json[s]) << endl;
    }
 
    return 0;
}

--------------------- 
//作者：海岛Blog 
//来源：CSDN 
//原文：https://blog.csdn.net/tigerisland45/article/details/81746280 
//版权声明：本文为博主原创文章，转载请附上博文链接！