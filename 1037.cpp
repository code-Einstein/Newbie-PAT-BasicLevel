/*
1037 在霍格沃茨找零钱 （20 分）
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱 P 和他实付的钱 A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：
输入在 1 行中分别给出 P 和 A，格式为 Galleon.Sickle.Knut，其间用 1 个空格分隔。这里 Galleon 是 [0, 10
​7
​​ ] 区间内的整数，Sickle 是 [0, 17) 区间内的整数，Knut 是 [0, 29) 区间内的整数。

输出格式：
在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

输入样例 1：
10.16.27 14.1.28
输出样例 1：
3.2.1
输入样例 2：
14.1.28 10.16.27
输出样例 2：
-3.2.1
*/

#include<iostream>
using namespace std;

void res(int a1, int a2, int a3, int b1, int b2, int b3) {
	int c1 = a1 - b1, c2 = a2 - b2, c3 = a3 - b3;
	if (c3 < 0) {
		c3 += 29;
		c2--;
	}
	if (c2 < 0) {
		c2 += 17;
		c1--;
	}
	printf("%d.%d.%d", c1, c2, c3);
}

int main() {
	int a1, a2, a3, b1, b2, b3;
	scanf("%d.%d.%d", &a1, &a2, &a3);
	scanf("%d.%d.%d", &b1, &b2, &b3);
	if (a1 > b1 || a1 == b1 && a2 > b2 || a1 == b1 && a2 == b2 && a3 > b3) {
		cout << "-";
		res(a1, a2, a3, b1, b2, b3);
	}
	else
		res(b1, b2, b3, a1, a2, a3);
	return 0;
}