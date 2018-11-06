/*
1018 锤子剪刀布 （20 分）
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

FigCJB.jpg

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第 1 行给出正整数 N（≤10
​5
​​ ），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	int n, win_jia = 0, win_yi = 0, draw_jia = 0, draw_yi = 0, lose_jia = 0, lose_yi = 0;
	int res_jia[3] = { 0 }, res_yi[3] = { 0 }; //0-C, 1-J, 2-B
	string jia, yi;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> jia >> yi;
		if (jia == "C" && yi == "J" || jia == "J" && yi == "B" || jia == "B" && yi == "C") {
			win_jia++; lose_yi++;
			if (jia == "C") res_jia[0]++;
			else if (jia == "J") res_jia[1]++;
			else res_jia[2]++;
		}
		else if (jia == yi) {
			draw_jia++;
			draw_yi++;
		}
		else {
			lose_jia++; win_yi++;
			if (yi == "C") res_yi[0]++;
			else if (yi == "J") res_yi[1]++;
			else res_yi[2]++;
		}
	}
	cout << win_jia << " " << draw_jia << " " << lose_jia << endl;
	cout << win_yi << " " << draw_yi << " " << lose_yi << endl;
	if (res_jia[0] >= res_jia[1] && res_jia[0] > res_jia[2])
		cout << "C ";
	else if (res_jia[1] > res_jia[0] && res_jia[1] > res_jia[2])
		cout << "J ";
	else
		cout << "B ";
	if (res_yi[0] >= res_yi[1] && res_yi[0] > res_yi[2])
		cout << "C";
	else if (res_yi[1] > res_yi[0] && res_yi[1] > res_yi[2])
		cout << "J";
	else
		cout << "B";
	return 0;
}