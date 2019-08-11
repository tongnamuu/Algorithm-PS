#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[51][51];
int b[51][51];
int temp[51][51];
int n, m, k;
struct pos {
	int x, y, r;
};
pos rotateInfo[9];
int getAnswer() {
	int ans = 2147483647;
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j <= m; ++j) {
			cnt += a[i][j];
		}
		if (ans > cnt) ans = cnt;
	}
	return ans;
}
void recover() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			a[i][j] = temp[i][j];
		}
	}
}
void rotate(int x, int y, int range) {
	if (range == 0) return;
	for (int i = y - range; i < y + range; ++i) {
		b[x - range][i + 1] = a[x - range][i];
	}
	for (int i = x - range; i < x + range; ++i) {
		b[i + 1][y + range] = a[i][y + range];
	}
	for (int i = y + range; i > y - range; --i) {
		b[x + range][i - 1] = a[x + range][i];
	}
	for (int i = x + range; i > x - range; --i) {
		b[i - 1][y - range] = a[i][y - range];
	}
	
	for (int i = y - range; i < y + range; ++i) {
		a[x - range][i] = b[x - range][i];
	}
	for (int i = x - range; i < x + range; ++i) {
		a[i][y + range] = b[i][y + range];
	}
	for (int i = y + range; i > y - range; --i) {
		a[x + range][i] = b[x + range][i];
	}
	for (int i = x + range; i > x - range; --i) {
		a[i][y - range] = b[i][y - range];
	}
	rotate(x, y, range - 1);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			temp[i][j] = a[i][j];
		}
	}
	vector<int> index;
	for (int i = 0; i < k; ++i) {
		cin >> rotateInfo[i].x >> rotateInfo[i].y >> rotateInfo[i].r;
		index.push_back(i);
	}
	int ans = 2147483647;
	do {
		recover();
		for (int i : index) {
			rotate(rotateInfo[i].x, rotateInfo[i].y, rotateInfo[i].r);
		}
		int cnt = getAnswer();
		if (ans > cnt) ans = cnt;
	} while (next_permutation(index.begin(), index.end()));
	cout << ans << '\n';
}