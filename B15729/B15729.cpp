#include <iostream>
using namespace std;
int a[1000000];
int b[1000000];
int n;
int ans = 2147483647;
void lighton(int index) {
	if (index + 1 < n) b[index + 1] ^= 1;
	if (index < n) b[index] ^= 1;
	if (index + 2 < n) b[index + 2] ^= 1;
}
void go(int index, int cnt) {
	if (index == n) {
		for (int i = 0; i < n; ++i) {
			if (a[i] != b[i]) {
				return;
			}
		}
		if (ans > cnt) ans = cnt;
		return;
	}
	if (a[index] == b[index]) {
		go(index + 1, cnt);
	}
	else {
		lighton(index);
		go(index + 1, cnt + 1);
		lighton(index);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	go(1, 0);
	lighton(0);
	go(1 ,1);
	lighton(0);
	cout << ans << '\n';
}