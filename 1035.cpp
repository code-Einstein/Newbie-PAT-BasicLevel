/*
1035 插入与归并 （25 分）
根据维基百科的定义：

插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。

归并排序进行如下迭代操作：首先将原始序列看成 N 个只包含 1 个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下 1 个有序的序列。

现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

输入格式：
输入在第一行给出正整数 N (≤100)；随后一行给出原始序列的 N 个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。

输出格式：
首先在第 1 行中输出Insertion Sort表示插入排序、或Merge Sort表示归并排序；然后在第 2 行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行首尾不得有多余空格。

输入样例 1：
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
输出样例 1：
Insertion Sort
1 2 3 5 7 8 9 4 6 0
输入样例 2：
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
输出样例 2：
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int n;

int* nextinsert(int a[100], int time) {
	sort(&a[0], &a[time + 1]);
	return a;
}

int* nextmerge(int a[100], int time) {
	int num = pow(2, time);
	for (int i = 0; i < n / num; i++)
		sort(&a[i*num + 0], &a[(i + 1)*num]);
	sort(&a[n - n%(int)num], &a[n]);
	return a;
}

int main() {
	int flag_out = 0, time = 1, a_insert[100] = { 0 }, a_merge[100] = { 0 }, b[100] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a_insert[i];
		a_merge[i] = a_insert[i];
	}
	for (int i = 0; i < n; i++)
		cin >> b[i];
	while (1) {
		if (flag_out)
			break;
		for (int i = 0; i < n; i++) {
			if (a_insert[i] == b[i]) {
				if (i == n - 1) {
					nextinsert(a_insert, time);
					cout << "Insertion Sort" << endl;
					for (int j = 0; j < n - 1; j++)
						cout << a_insert[j] << " ";
					cout << a_insert[n - 1] << endl;
					flag_out = 1;
				}
			}
			else {
				nextinsert(a_insert, time);
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if (a_merge[i] == b[i]) {
				if (i == n - 1) {
					nextmerge(a_merge, time);
					cout << "Merge Sort" << endl;
					for (int j = 0; j < n - 1; j++)
						cout << a_merge[j] << " ";
					cout << a_merge[n - 1] << endl;
					flag_out = 1;
				}
			}
			else {
				nextmerge(a_merge, time);
				break;
			}
		}
		time++;
	}
	return 0;
}