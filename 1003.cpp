/*
1003 ��Ҫͨ���� ��20 �֣�
������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ����������� PAT �ġ�����ȷ�������� ���� ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�

�ַ����б������ P�� A�� T�������ַ��������԰��������ַ���
�������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a�� b�� c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
���ھ�����Ϊ PAT дһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�

�����ʽ��
ÿ������������� 1 �������������� 1 �и���һ�������� n (<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ����� 100���Ҳ������ո�

�����ʽ��
ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ��������� YES��������� NO��

����������
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
���������
YES
YES
YES
YES
NO
NO
NO
NO
*/

#include<iostream>
#include<string>

using namespace std;

int main() {
	int time;
	cin >> time;
	for (int i = 0; i < time; i++) {
		string in;
		int p_time = 0, t_time = 0, p_loc = 0, t_loc = 0, isPAT = 1;
		cin >> in;
		for (int j = 0; j < in.length(); j++) {
			if (in[j] != 'A' && in[j] != 'P' && in[j] != 'T')
				isPAT = 0;
			if (in[j] == 'P') {
				p_time++;
				p_loc = j;
			}
			if (in[j] == 'T') {
				t_time++;
				t_loc = j;
			}		
		}
		if (isPAT == 1 && p_time == 1 && t_time == 1) {
			//û�������⣬ֻ�����������Ϳ��ԣ�������
			if ((t_loc - p_loc == 2 && p_loc == in.length() / 2 - 1) || (p_loc * (t_loc - p_loc - 1) == in.length() - t_loc - 1))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
			cout << "NO" << endl;
		in.clear();
	}
	return 0;
}