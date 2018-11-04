/*
1007 素数对猜想 （20 分）
让我们定义d
​n
​​ 为：d
​n
​​ =p
​n+1
​​ −p
​n
​​ ，其中p
​i
​​ 是第i个素数。显然有d
​1
​​ =1，且对于n>1有d
​n
​​ 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<10
​5
​​ )，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20
输出样例:
4
*/

#include<iostream>
#include<vector>
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
	int n, res = 0, pre = 0, cur;
	cin >> n;
	vector<int> num;
	for (int i = 3; i <= n; i++) {
		if (prime(i))
			num.push_back(i);
	}
	for (auto it : num) {
		cur = it;
		if (cur - pre == 2)
			res++;
		pre = cur;
	}
	cout << res;
	return 0;
}