/*
1043 输出PATest （20 分）
给定一个长度不超过 10
​4
​​  的、仅由英文字母构成的字符串。请将字符重新调整顺序，按 PATestPATest.... 这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按 PATest 的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过 10
​4
​​  的、仅由英文字母构成的非空字符串。

输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	string s, abc = "PATest";
	cin >> s;
	int num = 0, a[6] = { 0 };
	for (int i = 0; i < s.length(); i++) {
		if		(s[i] == 'P') a[0]++;
		else if (s[i] == 'A') a[1]++;
		else if (s[i] == 'T') a[2]++;
		else if (s[i] == 'e') a[3]++;
		else if (s[i] == 's') a[4]++;
		else if (s[i] == 't') a[5]++;
	}
	while (1) {
		if (a[0]) { cout << "P"; a[0]--; num++; }
		if (a[1]) { cout << "A"; a[1]--; num++; }
		if (a[2]) { cout << "T"; a[2]--; num++; }
		if (a[3]) { cout << "e"; a[3]--; num++; }
		if (a[4]) { cout << "s"; a[4]--; num++; }
		if (a[5]) { cout << "t"; a[5]--; num++; }
		if (!num) break;
		num = 0;
	}
	return 0;
}