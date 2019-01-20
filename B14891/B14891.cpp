#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int a[4][8];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 8; ++j) {
			scanf("%1d", &a[i][j]);
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int num, rot;
		cin >> num >> rot;
		int d[4] = { 0, };
		d[num - 1] = rot;
		for (int i = num - 2; i >= 0; --i) {
			if (a[i][2] != a[i + 1][6]) {
				d[i] = -d[i + 1];
			}
			else break;
		}
		for (int i = num ; i < 4; ++i) {
			if (a[i][6] != a[i - 1][2]) {
				d[i] = -d[i-1];
			}
			else break;
		}
		for (int i = 0; i < 4; ++i) {
			if (d[i] == 1) {
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
	for (int i = 0; i < 4; ++i) {
		if (a[i][0] == 1) {
			ans += (1 << i);
		}
	}
	cout << ans << '\n';
}