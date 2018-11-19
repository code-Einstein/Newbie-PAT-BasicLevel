/*
1035 ������鲢 ��25 �֣�
����ά���ٿƵĶ��壺

���������ǵ����㷨����һ����������ݣ��𲽲��������������С�ÿ�������У��㷨������������ȡ��һԪ�أ���֮����������������ȷ��λ�á���˵���ֱ��ȫ��Ԫ������

�鲢����������µ������������Ƚ�ԭʼ���п��� N ��ֻ���� 1 ��Ԫ�ص����������У�Ȼ��ÿ�ε����鲢�������ڵ����������У�ֱ�����ֻʣ�� 1 ����������С�

�ָ���ԭʼ���к���ĳ�����㷨�������м����У������жϸ��㷨���������������㷨��

�����ʽ��
�����ڵ�һ�и��������� N (��100)�����һ�и���ԭʼ���е� N �����������һ�и�����ĳ�����㷨�������м����С�������������Ŀ���������������ּ��Կո�ָ���

�����ʽ��
�����ڵ� 1 �������Insertion Sort��ʾ�������򡢻�Merge Sort��ʾ�鲢����Ȼ���ڵ� 2 ��������ø������㷨�ٵ���һ�ֵĽ�����С���Ŀ��֤ÿ����ԵĽ����Ψһ�ġ����ּ��Կո�ָ���������β�����ж���ո�

�������� 1��
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
������� 1��
Insertion Sort
1 2 3 5 7 8 9 4 6 0
�������� 2��
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
������� 2��
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