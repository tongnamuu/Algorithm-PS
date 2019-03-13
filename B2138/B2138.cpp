#include <iostream>
using namespace std;
int n;
int a[100000];
int b[100000];
int ans = 2147483647;
void togglelight(int index) {
	if (index - 1 >= 0) b[index - 1] ^= 1;
	if (index < n) b[index] ^= 1;
	if (index + 1 < n) b[index + 1] ^= 1;
}
void go(int index, int cnt) {
	if (index == n) {
		for (int i = 0; i < n; ++i) {
			if (a[i] != b[i]) return;
		}
		if (ans > cnt) ans = cnt;
		return;
	}
	if (a[index - 1] == b[index - 1]) {
		go(index + 1, cnt);
	}
	else {
		togglelight(index);
		go(index + 1, cnt + 1);
		togglelight(index);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%1d", &b[i]);
	for (int i = 0; i < n; ++i) scanf("%1d", &a[i]);
	go(1, 0);
	togglelight(0);
	go(1, 1);
	togglelight(0);
	if (ans == 2147483647) cout << -1 << '\n';
	else cout << ans << '\n';
}