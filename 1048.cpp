/*
1048 ���ּ��� ��20 �֣�
����Ҫ��ʵ��һ�����ּ��ܷ��������ȹ̶�һ�������������� A������һ������ B������ÿ 1 λ������ A �Ķ�Ӧλ���ϵ����ֽ����������㣺������λ����Ӧλ��������Ӻ�� 13 ȡ�ࡪ�������� J ���� 10��Q ���� 11��K ���� 12����ż��λ���� B �����ּ�ȥ A �����֣������Ϊ���������ټ� 10���������λΪ�� 1 λ��

�����ʽ��
������һ�������θ��� A �� B����Ϊ������ 100 λ��������������Կո�ָ���

�����ʽ��
��һ����������ܺ�Ľ����

����������
1234567 368782971
���������
3695Q8118
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int len;
	if (a.size() > b.size())
		len = b.size();
	else
		len = a.size();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < len; i++) {
		if (i % 2) {
			if (b[i] - a[i] < 0)
				b[i] = b[i] + 10 - a[i] + '0';
			else
				b[i] = b[i] - a[i] + '0';
		}
		else {
			if ((b[i] - '0' + a[i] - '0') % 13 == 10)
				b[i] = 'J';
			else if ((b[i] - '0' + a[i] - '0') % 13 == 11)
				b[i] = 'Q';
			else if ((b[i] - '0' + a[i] - '0') % 13 == 12)
				b[i] = 'K';
			else
				b[i] = (b[i] - '0' + a[i] - '0') % 13 + '0';
		}
	}
	reverse(b.begin(), b.end());
	int flag = 1;
	for (int i = 0; i < b.size(); i++) {
		if (flag && b[i] == '0');
		else {
			flag = 0;
			cout << b[i];
		}
	}
	if (flag == 1)
		cout << "0";
	return 0;
}