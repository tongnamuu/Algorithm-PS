#include <iostream>
using namespace std;
int d, w, k;
int a[14][21];
int ans;
bool checksero(int index) {
	int sum = 0;
	for (register int i = 0; i < k; ++i) sum += a[i][index];
	if (sum == k || sum == 0) return true;
	for (register int i = 0; i + k < d; ++i) {
		sum -= a[i][index];
		sum += a[i + k][index];
		if (sum == k || sum == 0) return true;
	}
	return false;
}
bool checkmap() {
	for (register int i = 0; i < w; ++i) {
		if (!checksero(i)) return false;
	}
	return true;
}
void makesame(int index, int drug) {
	for (register int i = 0; i < w; ++i) {
		a[index][i] = drug;
	}
}
void go(int index, int cnt) {
	if (cnt > k) return;
	if (index == d) {
		if (checkmap()) {
			if (ans > cnt) ans = cnt;
		}
		return;
	}
	go(index + 1, cnt);
	int temp[21] = { 0, };
	for (register int i = 0; i < w; ++i) {
		temp[i] = a[index][i];
	}
	makesame(index, 0);
	go(index + 1, cnt + 1);
	makesame(index, 1);
	go(index + 1, cnt + 1);
	for (register int i = 0; i < w; ++i) {
		a[index][i] = temp[i];
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> d >> w >> k;
		ans = k;
		for (register int i = 0; i < d; ++i) {
			for (register int j = 0; j < w; ++j) {
				cin >> a[i][j];
			}
		}
		go(0, 0);
		makesame(0, 0);
		go(1, 1);
		makesame(0, 1);
		go(1, 1);
		cout << '#' << tc << ' ' << ans << '\n';
	}
}