/*
1048 数字加密 （20 分）
本题要求实现一种数字加密方法。首先固定一个加密用正整数 A，对任一正整数 B，将其每 1 位数字与 A 的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对 13 取余——这里用 J 代表 10、Q 代表 11、K 代表 12；对偶数位，用 B 的数字减去 A 的数字，若结果为负数，则再加 10。这里令个位为第 1 位。

输入格式：
输入在一行中依次给出 A 和 B，均为不超过 100 位的正整数，其间以空格分隔。

输出格式：
在一行中输出加密后的结果。

输入样例：
1234567 368782971
输出样例：
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