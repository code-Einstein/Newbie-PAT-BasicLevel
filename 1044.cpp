/*
1044 �������� ��20 �֣�
���������� 13 ���Ƽ����ģ�

�����˵� 0 �������˳�Ϊ tret��
���������� 1 �� 12 �Ļ����ķֱ�Ϊ��jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec��
�����˽���λ�Ժ�� 12 ����λ���ֱַ��Ϊ��tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou��
��������˵����� 29 ����ɻ����ľ��� hel mar���������� elo nov ��Ӧ�������� 115��Ϊ�˷��㽻���������д����ʵ�ֵ���ͻ�������֮��Ļ��롣

�����ʽ��
�����һ�и���һ�������� N��<100������� N �У�ÿ�и���һ�� [0, 169) �����ڵ����� ���� �����ǵ����ģ������ǻ����ġ�

�����ʽ��
��Ӧ�����ÿһ�У���һ���������������һ�����Ե����֡�

����������
4
29
5
elo nov
tam
���������
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