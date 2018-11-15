/*
1034 �������������� ��20 �֣�
����Ҫ���д���򣬼��� 2 ���������ĺ͡�������̡�

�����ʽ��
������һ���а��� a1/b1 a2/b2 �ĸ�ʽ��������������ʽ�������������з��Ӻͷ�ĸȫ�����ͷ�Χ�ڵ�����������ֻ���ܳ����ڷ���ǰ����ĸ��Ϊ 0��

�����ʽ��
�ֱ��� 4 ���а��� ������1 ����� ������2 = ��� �ĸ�ʽ˳����� 2 ���������ĺ͡�������̡�ע�������ÿ�������������Ǹ��������������ʽ k a/b������ k ���������֣�a/b �����������֣���Ϊ��������������ţ���������ĸΪ 0������� Inf����Ŀ��֤��ȷ�������û�г������ͷ�Χ��������

�������� 1��
2/3 -4/2
������� 1��
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
�������� 2��
5/3 0/6
������� 2��
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