/*
1024 科学计数法 （20 分）
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，即数字的整数部分只有 1 位，小数部分至少有 1 位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。

输入格式：
每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。

输出格式：
对每个测试用例，在一行中按普通数字表示法输出 A，并保证所有有效位都被保留，包括末尾的 0。

输入样例 1：
+1.23400E-03
输出样例 1：
0.00123400
输入样例 2：
-1.2E+10
输出样例 2：
-12000000000
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	char num[10000] = { 0 };
	cin >> s;
	if (s[0] == '-')
		cout << "-";
	int idx_point, idx_e, cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'E') {
			idx_e = i;
			break;
		}
		else if (s[i] == '.')
			idx_point = i;
	}
	for (int i = idx_e + 2; i < s.size(); i++)
		cnt = cnt * 10 + (s[i] - '0');
	if (s[idx_e + 1] == '-') cnt = -cnt;
	num[0] = s[1];
	for (int i = 3; i < idx_e; i++)
		num[i - 2] = s[i];

	if (cnt > idx_e - idx_point) {
		cout << num;
		for (int i = 0; i <= cnt - (idx_e - idx_point); i++)
			cout << "0";
	}
	else if (cnt > 0) {
		int i;
		for (i = 0; i <= cnt; i++)
			cout << num[i];
		cout << ".";
		for (; i < idx_e - 2; i++)
			cout << num[i];
	}
	else if (cnt == 0) {
		cout << num[0] << ".";
		for (int i = 1; i < idx_e - 2; i++)
			cout << num[i];
	}
	else {
		cout << "0.";
		for (int i = 0; i < -cnt - 1; i++)
			cout << "0";
		cout << num;
	}
	return 0;
}