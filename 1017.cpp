/*
1017 A除以B （20 分）
本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。

输入格式：
输入在一行中依次给出 A 和 B，中间以 1 空格分隔。

输出格式：
在一行中依次输出 Q 和 R，中间以 1 空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
*/

#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char a[1000] = { 0 }, q[1000] = { 0 };
	int b, r = 0, lenA;
	cin >> a >> b;
	lenA = strlen(a);
	if (a[1] == 0 && a[0] - '0' < b)
		cout << "0 " << a[0];
	else if (a[1] == 0 && a[0] - '0' == b)
		cout << "1 0";
	else {
		for (int i = 0; i < lenA; i++) {
			r = r * 10 + a[i] - '0';
			q[i] = r / b + '0';
			r %= b;
		}
		int i = 0;
		while (q[i] == '0') i++;
		for (; i < lenA; i++)
			cout << q[i];
		cout << " " << r;
	}
	return 0;
}