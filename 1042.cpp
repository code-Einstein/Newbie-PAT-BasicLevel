/*
1042 �ַ�ͳ�� ��20 �֣�
���д�����ҳ�һ�θ��������г�����Ƶ�����Ǹ�Ӣ����ĸ��

�����ʽ��
������һ���и���һ�����Ȳ����� 1000 ���ַ������ַ����� ASCII ���������ɼ��ַ����ո���ɣ����ٰ��� 1 ��Ӣ����ĸ���Իس��������س��������ڣ���

�����ʽ��
��һ�����������Ƶ����ߵ��Ǹ�Ӣ����ĸ������ִ���������Կո�ָ�������в��У����������ĸ����С���Ǹ���ĸ��ͳ��ʱ�����ִ�Сд�����Сд��ĸ��

����������
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
���������
e 7
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	int a[26] = { 0 }, b[26] = { 0 }, max_idx = 0, max_num = 0;
	string s, abc = "abcdefghijklmnopqrstuvwxyz";
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			a[s[i] - 'a']++;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			b[s[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (a[i] + b[i] > max_num) {
			max_idx = i;
			max_num = a[i] + b[i];
		}
	}
	cout << abc[max_idx] << " " << max_num << endl;
	return 0;
}