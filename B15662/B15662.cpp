#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int T;
	int circle;
	cin >> circle;
	int a[1000][8];
	for (int i = 0; i < circle; ++i) {
		for (int j = 0; j < 8; ++j) {
			scanf("%1d", &a[i][j]);
		}
	}
	cin >> T;
	while (T--) {
		int num, cmd;
		cin >> num >> cmd;
		int d[1000] = { 0, };
		d[num - 1] = cmd;
		for (int i = num - 2; i >= 0; --i) {
			if (a[i][2] != a[i + 1][6]) {
				d[i] = -d[i + 1];
			}
		}
		for (int i = num; i < circle; ++i) {
			if (a[i - 1][2] != a[i][6]) {
				d[i] = -d[i - 1];
			}
		}
		for (int i = 0; i < circle; ++i) {
			if (d[i] == 1) {//시계방향
				int temp = a[i][7];
				a[i][7] = a[i][6];
				a[i][6] = a[i][5];
				a[i][5] = a[i][4];
				a[i][4] = a[i][3];
				a[i][3] = a[i][2];
				a[i][2] = a[i][1];
				a[i][1] = a[i][0];
				a[i][0] = temp;
			}
			else if (d[i] == -1) {
				int temp = a[i][0];
				a[i][0] = a[i][1];
				a[i][1] = a[i][2];
				a[i][2] = a[i][3];
				a[i][3] = a[i][4];
				a[i][4] = a[i][5];
				a[i][5] = a[i][6];
				a[i][6] = a[i][7];
				a[i][7] = temp;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < circle; ++i) {
		if (a[i][0] == 1) ans++;
	}
	cout << ans << '\n';
}