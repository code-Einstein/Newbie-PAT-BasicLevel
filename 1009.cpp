/*
1009 ˵���� ��20 �֣�
����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ������

�����ʽ��
�����������һ��������������һ���ڸ����ܳ��Ȳ����� 80 ���ַ������ַ��������ɵ��ʺ����ɿո���ɣ����е�������Ӣ����ĸ����Сд�����֣���ɵ��ַ���������֮���� 1 ���ո�ֿ������뱣֤����ĩβû�ж���Ŀո�

�����ʽ��
ÿ���������������ռһ�У���������ľ��ӡ�

����������
Hello World Here I Come
���������
Come I Here World Hello
*/

#include<iostream>
#include<string>
#include<sstream>
#include<list>
using namespace std;

int main() {
	string s1, s2;
	stringstream sout;
	list<string> res;
	getline(cin, s1);
	sout.clear();
	sout.str(s1);
	while (sout >> s2)
		res.push_back(s2);
	res.reverse();
	int i = res.size();
	if (i != 1) {
		for (auto it : res) {
			cout << it << " ";
			i--;
			if (i == 1) break;
		}
	}
	cout << res.back();
	return 0;
}