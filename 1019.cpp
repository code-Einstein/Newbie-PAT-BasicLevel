/*
1019 数字黑洞 （20 分）
给定任一个各位数字不完全相同的 4 位正整数，如果我们先把 4 个数字按非递增排序，再按非递减排序，然后用第 1 个数字减第 2 个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的 6174，这个神奇的数字也叫 Kaprekar 常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
现给定任意 4 位正整数，请编写程序演示到达黑洞的过程。

输入格式：
输入给出一个 (0,10
​4
​​ ) 区间内的正整数 N。

输出格式：
如果 N 的 4 位数字全相等，则在一行内输出 N - N = 0000；否则将计算的每一步在一行内输出，直到 6174 作为差出现，输出格式见样例。注意每个数字按 4 位数格式输出。

输入样例 1：
6767
输出样例 1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例 2：
2222
输出样例 2：
2222 - 2222 = 0000
*/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int down(int x) {
	int a[4];
	a[0] = x % 10;
	a[1] = x / 10 % 10;
	a[2] = x / 100 % 10;
	a[3] = x / 1000 % 10;
	sort(a, a + 4, cmp);
	return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}

int up(int x) {
	int a[4];
	a[0] = x % 10;
	a[1] = x / 10 % 10;
	a[2] = x / 100 % 10;
	a[3] = x / 1000 % 10;
	sort(a, a + 4, cmp);
	return a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
}

int main() {
	int n;
	cin >> n;
	if (n == down(n) && n == up(n)) {
		cout << n << " - " << n << " = 0000" << endl;
		return 0;
	}
	while (down(n) - up(n) != 6174) {
		cout << down(n);
		if (up(n) > 999)
			cout << " - " << up(n);
		else if (up(n) > 99)
			cout << " - 0" << up(n);
		else if (up(n) > 9)
			cout << " - 00" << up(n);
		else
			cout << " - 000" << up(n);
		if (down(n) - up(n) > 999)
			cout << " = " << down(n) - up(n) << endl;
		else if (down(n) - up(n) > 99)
			cout << " = 0" << down(n) - up(n) << endl;
		else if (down(n) - up(n) > 9)
			cout << " = 00" << down(n) - up(n) << endl;
		else
			cout << " = 000" << down(n) - up(n) << endl;
		n = down(n) - up(n);
	}
	cout << down(n);
	if (up(n) > 999)
		cout << " - " << up(n) << " = 6174" << endl;
	else if (up(n) > 99)
		cout << " - 0" << up(n) << " = 6174" << endl;
	else if (up(n) > 9)
		cout << " - 00" << up(n) << " = 6174" << endl;
	else
		cout << " - 000" << up(n) << " = 6174" << endl;
	return 0;
}