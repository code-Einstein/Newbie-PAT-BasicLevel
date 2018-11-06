/*
1022 D进制的A+B （20 分）
输入两个非负 10 进制整数 A 和 B (≤2
​30
​​ −1)，输出 A+B 的 D (1<D≤10)进制数。

输入格式：
输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：
输出 A+B 的 D 进制数。

输入样例：
123 456 8
输出样例：
1103
*/

#include<iostream>
using namespace std;

void out(int c, int d) {
	if (c) {
		int tmp = c % d;
		c /= d;
		out(c, d);
		cout << tmp;
	}
}

int main() {
	int a, b, d;
	cin >> a >> b >> d;
	int c = a + b;
	if (c)
		out(c, d);
	else
		cout << "0";
	return 0;
}