/*
1034 有理数四则运算 （20 分）
本题要求编写程序，计算 2 个有理数的和、差、积、商。

输入格式：
输入在一行中按照 a1/b1 a2/b2 的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为 0。

输出格式：
分别在 4 行中按照 有理数1 运算符 有理数2 = 结果 的格式顺序输出 2 个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式 k a/b，其中 k 是整数部分，a/b 是最简分数部分；若为负数，则须加括号；若除法分母为 0，则输出 Inf。题目保证正确的输出中没有超过整型范围的整数。

输入样例 1：
2/3 -4/2
输出样例 1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例 2：
5/3 0/6
输出样例 2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/

#include<iostream>
#include<cstdlib>
using namespace std;

long long max(long long a, long long b) {
	long long t;
	if (a < b) {
		t = a; a = b; b = t;
	}
	while (t = a % b) {
		a = b; b = t;
	}
	return b;
}

void yue(long long zi, long long mu) {
	long long max_yue = max(zi, mu);
	zi /= max_yue;
	mu /= max_yue;
	if (zi / mu) {
		cout << zi / mu;
		if (zi % mu)
			cout << " " << zi % mu << "/" << mu;
	}
	else
		cout << zi << "/" << mu;
}

void simple(long long zi, long long mu) {
	if (!zi) {
		cout << "0";
		return;
	}
	else if (zi > 0 && mu > 0 || zi < 0 && mu < 0) {
		zi = abs(zi); mu = abs(mu);
		yue(zi, mu);
	}
	else {
		cout << "(-";
		zi = abs(zi); mu = abs(mu);
		yue(zi, mu);
		cout << ")";
	}
}

int main() {
	long long a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	simple(a1, b1); cout << " + "; simple(a2, b2); cout << " = "; simple(a1*b2 + a2*b1, b1*b2); cout << endl;
	simple(a1, b1); cout << " - "; simple(a2, b2); cout << " = "; simple(a1*b2 - a2*b1, b1*b2); cout << endl;
	simple(a1, b1); cout << " * "; simple(a2, b2); cout << " = "; simple(a1*a2		  , b1*b2); cout << endl;
	simple(a1, b1); cout << " / "; simple(a2, b2); cout << " = "; if (!a2) cout << "Inf"; else
																  simple(a1*b2		  , b1*a2); cout << endl;
	return 0;
}