#include <iostream>
#include <string>
using namespace std;
int n;
int d[8][8] = { 0, };
int a[8];
int ans;
bool go2(string s) {
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (d[i][j] && s[i] == s[j]) return false;
		}
	}
	return true;
}
void go(string now) {
	int len = now.length();
	if (len == n) {
		int cnt = 0;
		if (!go2(now)) return;
		for (int i = 0; i < len; ++i) {
			if ((now[i] - '0') != a[i])
				cnt++;
		}
		if (cnt < ans) ans = cnt;
		return;
	}
	for (int i = 1; i <= 4; ++i) {
		go(now + (char)(i + '0'));
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		ans = 2147483647;
		for (int i = 0; i < n; ++i) cin >> a[i];	
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> d[i][j];
		go("1");
		go("2");
		go("3");
		go("4");
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}