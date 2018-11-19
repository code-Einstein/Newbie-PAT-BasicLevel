/*
1044 火星数字 （20 分）
火星人是以 13 进制计数的：

地球人的 0 被火星人称为 tret。
地球人数字 1 到 12 的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的 12 个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字 29 翻译成火星文就是 hel mar；而火星文 elo nov 对应地球数字 115。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：
输入第一行给出一个正整数 N（<100），随后 N 行，每行给出一个 [0, 169) 区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：
对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13
*/

#include<iostream>
#include<string>
using namespace std;

string abc_low[13]  = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string abc_high[13] = { "tres", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void int_to_string(string s, int len) {
	int num = 0, high, low;
	if (len == 3) num = 100 + (s[1] - '0') * 10 + (s[2] - '0');
	else if (len == 2) num = (s[0] - '0') * 10 + (s[1] - '0');
	else num = s[0] - '0';
	high = num / 13;
	low = num % 13;
	if (num < 13)
		cout << abc_low[num] << endl;
	else {
		if (num % 13 == 0)
			cout << abc_high[num / 13] << endl;
		else
			cout << abc_high[num / 13] << " " << abc_low[num % 13] << endl;
	}
}

void string_to_int(string s, int len) {
	if (len < 5) {
		for (int i = 0; i < 13; i++) {
			if (s == abc_low[i]) {
				cout << i << endl;
				return;
			}
			else if (s==abc_high[i]) {
				cout << i * 13 << endl;
				return;
			}
		}
	}
	else {
		int res = 0;
		string ss = s.substr(0, 3);
		for (int i = 0; i < 13; i++) {
			if (ss == abc_high[i]) {
				res += i * 13;
				break;
			}
		}
		ss = s.substr(4, 3);
		for (int i = 0; i < 13; i++) {
			if (ss == abc_low[i]) {
				res += i;
				break;
			}
		}
		cout << res << endl;
	}
}

int main() {
	int n;
	string s;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		int len = s.length();
		if (s[0] >= '0' && s[0] <= '9')
			int_to_string(s, len);
		else
			string_to_int(s, len);
	}
	return 0;
}