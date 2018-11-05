/*
1013 数素数 （20 分）
令 P
​i
​​  表示第 i 个素数。现任给两个正整数 M≤N≤10
​4
​​ ，请输出 P
​M
​​  到 P
​N
​​  的所有素数。

输入格式：
输入在一行中给出 M 和 N，其间以空格分隔。

输出格式：
输出从 P
​M
​​  到 P
​N
​​  的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

#include<iostream>
#include<cmath>
using namespace std;

bool prime(int x) {
	bool ret = true;
	int bound = sqrt(x) + 1;
	for (int i = 2; i < bound; i++) {
		if (x % i == 0) {
			ret = false;
			break;
		}
	}
	return ret;
}

int main() {
	int m, n, idx = 0, num = 2, line = 0;
	cin >> m >> n;
	while (idx < n) {
		if (prime(num)) {
			if (idx >= m - 1) {
				cout << num;
				if (line == 9) {
					cout << "\n";
					line = 0;
				}
				else if (idx == n - 1)
					return 0;
				else {
					cout << " ";
					line++;
				}
			}
			idx++;
		}
		num++;
	}
	return 0;
}