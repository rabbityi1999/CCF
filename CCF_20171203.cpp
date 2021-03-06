// CCF_20171203.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

#define MINUTE 0
#define HOUR 1
#define DAY 2
#define MONTH 3
#define WEEK 4


using  namespace std;

struct both {
	string has[2];
};
struct CROB {
	vector<both> min;
	vector<both> hour;
	vector<both> day;
	vector<both> month;
	vector<both> week;
	string com;
};



struct TIME {
	int year;
	int month;
	int day;
	int hour;
	int min;
};


struct TIME Begin, End;

/*
12.24~3.37写完开始debug
debug2个小时不到，快点一个小时左右
需要把所有的输入输出都总结一下了
字符串转换函数，
引用和指针调用
map <string, int> mon_map;
*/


void assign(struct TIME& Begin,string begintime) {
	Begin.year = atoi(begintime.substr(0, 4).c_str());
	Begin.month = atoi(begintime.substr(4, 2).c_str());
	Begin.day = atoi(begintime.substr(6, 2).c_str());
	Begin.hour = atoi(begintime.substr(8, 2).c_str());
	Begin.min = atoi(begintime.substr(10, 2).c_str());
}
int mon_change(string s) {
	if (s == "jan")return 1;
	else if (s == "feb") return 2;
	else if (s == "mar")  return 3;
	else if (s == "apr") return 4;
	else if (s == "may") return 5;
	else if (s == "jun")return 6;
	else if (s == "jul")return 7;
	else if (s == "aug")return 8;
	else if (s == "sep")return 9;
	else if (s == "oct")return 10;
	else if (s == "nov")return 11;
	else if (s == "dec")return 12;
	else return 0;
}
int week_change(string s) {
	if (s == "sun")return 0;
	else if (s == "mon") return 1;
	else if (s == "tue")  return 2;
	else if (s == "wed") return 3;
	else if (s == "thu") return 4;
	else if (s == "fri")return 5;
	else if (s == "sat")return 6;
	else return -1;
}


void invent_each(string min, vector<both>& one,int sign) {
	int i,k;
	string input;
	string inside[2];
	struct both it;
	for (i = 0; i < min.length(); i++) {
		if (min[i] == ',') min[i] = ' ';
		min[i] = tolower(min[i]);
	}
	istringstream in(min);
	while (in >> input) {
		k = input.find('-');
		if (k != -1) {
			inside[0] = input.substr(0, k);
			inside[1] = input.substr(k + 1, input.length() - k - 1);
		}
		else {
			inside[0] = input;
			inside[1] = input;
		}
		if (sign == MONTH) {
			if (mon_change(inside[0]) != 0)
				inside[0] = to_string(mon_change(inside[0]));
			if (mon_change(inside[1]) != 0)
				inside[1] = to_string(mon_change(inside[1]));
		}
		else if(sign==WEEK){
			if (week_change(inside[0]) >=0)
				inside[0] = to_string(week_change(inside[0]));
			if (week_change(inside[1]) >=0)
				inside[1] = to_string(week_change(inside[1]));
		}
		it.has[0] = inside[0];
		it.has[1] = inside[1];
		one.push_back(it);
	}
}

void invent(struct CROB& one){
	string input,min,hour,day,mon,week;
	int i, j, k;
	getline(cin,input);
	istringstream in(input);
	in >> min >> hour >> day >> mon >> week>>one.com;

	//min
	invent_each(min, one.min,MINUTE);
	
	//hour
	invent_each(hour, one.hour,HOUR);

	//day
	invent_each(day, one.day,DAY);

	//mon
	invent_each(mon, one.month,MONTH);

	//week
	invent_each(week, one.week,WEEK);
}

//a时间比b大就要返回0
int bigger(struct TIME a,struct TIME b) {
	if (a.year > b.year)
		return 0;
	else if (a.year < b.year)
		return 1;
	else {
		if (a.month > b.month)
			return 0;
		else if (a.month < b.month) {
			return 1;
		}
		else {
			if (a.day > b.day)
				return 0;
			else if (a.day < b.day)
				return 1;
			else {
				if (a.hour > b.hour)
					return 0;
				else if (a.hour < b.hour)
					return 1;
				else {
					if (a.min >= b.min)
						return 0;
					else if (a.min < b.min)
						return 1;
				}
			}
		}
	}
}
int runnian(int year) {
	if (year % 4 != 0){
		return 0;
	}
	else {
		if (year % 100 != 0) {
			return 1;
		}
		else {
			if (year % 400 == 0)
				return 1;
			else
				return 0;
		}
	}
}
int cal_week(struct TIME now) {
	int i,j,sum=0;
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (i = 1970; i < now.year; i++) {
		if (runnian(i) == 1)
			sum = sum + 366;
		else
			sum = sum + 365;
	}
	for (i = 1; i < now.month;i++) {
		sum = sum + mon[i-1];
	}
	if (now.month > 2&& runnian(now.year) == 1)
		sum++;
	sum = sum + now.day-1;
	sum = sum % 7 + 4;
	return((sum)% 7);
}

 
int each(vector<both> a,int sat) {
	int i,ok;
	if (a[0].has[0] == "*")
		return 1;
	for (i = 0,ok=0; i < a.size(); i++) {
		if (sat >= atoi(a[i].has[0].c_str()) && sat <= atoi(a[i].has[1].c_str())) {
			ok = 1;
			break;
		}
	}
	return ok;
}
int among(struct TIME now, struct CROB one) {
	if (each(one.day, now.day))
		if (each(one.month, now.month))
			if (each(one.hour, now.hour))
				if (each(one.min, now.min))
					if (each(one.week, cal_week(now)))
						return 1;
	return 0;

}

void grow(struct TIME& now) {
	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (runnian(now.year) == 1)
		day[1]++;

	now.min++;
	if (now.min > 59) {
		now.min = 0;
		now.hour++;
		if (now.hour > 23) {
			now.hour = 0;
			now.day++;
			if (now.day > day[now.month - 1]) {
				now.day = 1;
				now.month++;
				if (now.month > 12) {
					now.month = 1;
					now.year++;
				}
			}
		}
	}
}
int main()
{
	/*
	int n, i, j, k;
	string begintime,endtime,input;
	vector <CROB> timelist;
	getline(cin, input);
	istringstream  in(input);
	in >> n>> begintime>>endtime;
	assign(Begin, begintime);
	assign(End, endtime);

	for (i = 0; i < n;i++) {
		CROB newone;
		invent(newone);
		timelist.push_back(newone);
	}
	while (bigger(Begin,End)) {
		for (i = 0; i < timelist.size();i++) {
			if (among(Begin, timelist[i])) {//匹配成功
				cout << Begin.year;
				if (Begin.month < 10)
					cout << "0"<< Begin.month;
				else
					cout<< Begin.month;
				if(Begin.day<10)
					cout << "0" << Begin.day;
				else
					cout << Begin.day;
				if (Begin.hour < 10)
					cout << "0" << Begin.hour;
				else
					cout << Begin.hour;
				if (Begin.min < 10)
					cout << "0" << Begin.min;
				else
					cout << Begin.min;

				cout<< " " << timelist[i].com << endl;
			}
		}
		grow(Begin);
	}
	return 0;
	*/

	int n, ct = 0;
	char ch;
	ch = cin.get();
	while (ch != '\n') {//数一行的个数
		cout << ch;
		ct++;
		ch = cin.get();
	}
	cout << ct << endl;
	return 0;
	
}

