#include <iostream>
#include <memory.h>
using namespace std;
bool check[1000000][10];
int n;
int ans;
int len;
int a[7];
int getnum() {
	int num = 0;
	for (int i = 0; i < len; ++i) {
		num *= 10;
		num += a[i];
	}
	return num;
}
void go(int cnt) {
	if (cnt == n) {
		int val = getnum();
		if (ans < val)
			ans = val;
		return;
	}
	for (register int i = 0; i < len; ++i) {
		for (register int j = i + 1; j < len; ++j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			int now = getnum();
			if (!check[now][cnt]) {
				check[now][cnt] = true; go(cnt + 1);
			}
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		char s[7];
		cin >> s;
		cin >> n;
		memset(check, false, sizeof(check));
		for (len = 0; s[len]; ++len) {
			a[len] = s[len] - '0';
		}
		ans = 0;
		go(0);
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}