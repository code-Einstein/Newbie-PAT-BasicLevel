/*
1042 字符统计 （20 分）
请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

输入格式：
输入在一行中给出一个长度不超过 1000 的字符串。字符串由 ASCII 码表中任意可见字符及空格组成，至少包含 1 个英文字母，以回车结束（回车不算在内）。

输出格式：
在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

输入样例：
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
输出样例：
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