/*
1017 A����B ��20 �֣�
����Ҫ����� A/B������ A �ǲ����� 1000 λ����������B �� 1 λ������������Ҫ������� Q ������ R��ʹ�� A=B��Q+R ������

�����ʽ��
������һ�������θ��� A �� B���м��� 1 �ո�ָ���

�����ʽ��
��һ����������� Q �� R���м��� 1 �ո�ָ���

����������
123456789050987654321 7
���������
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