/*
1024 ��ѧ������ ��20 �֣�
��ѧ�������ǿ�ѧ��������ʾ�ܴ���С�����ֵ�һ�ַ���ķ�����������������ʽ [+-][1-9].[0-9]+E[+-][0-9]+�������ֵ���������ֻ�� 1 λ��С������������ 1 λ�������ּ���ָ�����ֵ������ż�ʹ������Ҳ�ض���ȷ������

���Կ�ѧ�������ĸ�ʽ����ʵ�� A�����д������ͨ���ֱ�ʾ����� A������֤������Чλ����������

�����ʽ��
ÿ��������� 1 ��������������һ���Կ�ѧ��������ʾ��ʵ�� A�������ֵĴ洢���Ȳ����� 9999 �ֽڣ�����ָ���ľ���ֵ������ 9999��

�����ʽ��
��ÿ��������������һ���а���ͨ���ֱ�ʾ����� A������֤������Чλ��������������ĩβ�� 0��

�������� 1��
+1.23400E-03
������� 1��
0.00123400
�������� 2��
-1.2E+10
������� 2��
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