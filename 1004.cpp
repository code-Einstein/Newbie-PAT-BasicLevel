/*
1004 �ɼ����� ��20 �֣�
���� n��>0����ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�

�����ʽ��
ÿ������������� 1 ��������������ʽΪ

�� 1 �У������� n
�� 2 �У��� 1 ��ѧ�������� ѧ�� �ɼ�
�� 3 �У��� 2 ��ѧ�������� ѧ�� �ɼ�
... ... ...
�� n+1 �У��� n ��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������ 10 ���ַ����ַ������ɼ�Ϊ 0 �� 100 ֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�

�����ʽ��
��ÿ������������� 2 �У��� 1 ���ǳɼ����ѧ����������ѧ�ţ��� 2 ���ǳɼ����ѧ����������ѧ�ţ��ַ������� 1 �ո�

����������
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
���������
Mike CS991301
Joe Math990112
*/

#include<iostream>
#include<string>

using namespace std;

int main() {
	int n, score[100] = { 0 }, max = 0, min = 100, idx_max = 0, idx_min = 0;
	string name[100], num[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name[i] >> num[i] >> score[i];
		if (score[i] > max) {
			max = score[i];
			idx_max = i;
		}
		if (score[i] < min) {
			min = score[i];
			idx_min = i;
		}
	}
	cout << name[idx_max] << " " << num[idx_max] << endl;
	cout << name[idx_min] << " " << num[idx_min] << endl;
	return 0;
}