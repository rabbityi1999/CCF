#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
/*说明：
20180903
从70分到80分改变了大小写的识别*/
struct IP {
	unsigned int line;
	string key;
	string id;
	unsigned int prev;
	unsigned int layer;
};
typedef struct IP ip_s;
string change(string s) {
	int j;
	if (s[0] != '#') {
		for (j = 0; j < s.size(); j++)
			s[j] = tolower(s[j]);
	}
	return s;
}
int main()
{
	vector<IP> a;
	vector<int> result;
	vector<string> words;
	vector<IP>::iterator it = a.end();
	vector<string>::iterator it_w;
	int n, m, i, j, k, sum,p,q,have_id,last;
	char now[1000];
	string now_s;
	cin >> n >> m;
	
	//开始输入查询参考
	for (i = 0; i < n; i++) {
		getchar();
		memset(now,0,1000);
		cin.get(now, 1000);
		now_s = now;
		ip_s newone;
		newone.line = i + 1;
		for (j = 0, sum = 0,have_id=0; ; j++) {
			if (now[j] == '.')
				sum++;
			else if (j == strlen(now)) {
				if (have_id) {
					newone.key = change(now_s.substr(sum, have_id -sum));
					newone.id = change(now_s.substr(have_id+1,j-have_id-1));
				}
				else {
					newone.key = change(now_s.substr(sum,j-sum));
				}
				newone.layer = sum / 2;
				k = i - 1;//找到上一个元素
				if(k<0)
					newone.prev = 0;
				else {
					while (a[k].layer > newone.layer) {
						k = a[k].prev-1;//k代表在容器中的位置
					}
					if (a[k].layer == newone.layer)
						newone.prev = a[k].prev;
					else if (a[k].layer < newone.layer)
						newone.prev = k+1;
				}
				a.push_back(newone);
				break;
			}
			else if (now[j] == ' ') {
				have_id = j;//have_id是空白格的位置
			}
		}
	}
	//开始查询
	
	for (i = 0; i < m; i++) {
		getchar();
		memset(now, 0, 1000);
		cin.get(now,1000);
		now_s=now;
		
		for (j = 0,k=0,last=0,words.clear(),result.clear(); j <=strlen(now);j++) {//分词
			if (now[j] == ' '|| j == strlen(now) ){
				words.push_back(change(now_s.substr(k, j - k)));
				last++;
				k = j + 1;
			}
		} 
		for (p = a.size()-1; p >= 0;) {//从后往前匹配
			for (k=p,j = last - 1; j >= 0&&k>=0; ) {//从最后一个词开始匹配
				if ( (a[k].id == words[j] || a[k].key == words[j]) && (find( result.begin(),result.end(),k ) == result.end()) ) {//一个单词，匹配成功,需要继续匹配，寻找j的前辈
					j--; k=a[k].prev-1;//prev代表行号，因此这里序号还需减掉
					continue;
				}
				else {
					break;
				}
			}
			if (j>=0) {//说明还没有匹配完呢,这一次失败了
				p--;
			}
			else if(j<0){//说明已经匹配完了
				result.push_back(p);//记录
				p--;
			}
			//如果找到最前面了都没有找到说明需要重新匹配
		}

		cout << result.size();
		for (j = result.size() - 1; j >= 0;j--) {
			cout << " "<< result[j]+1;
		}
		cout << endl;
	}
	
}