#include <iostream>
using namespace std;
char a[1001];
int length;
int d[1001][1001];
void init() {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (i == j) d[i][j] = 1;
			else d[i][j] = 0;
		}
	}
	for (int i = 0; i + 1 < length; ++i) if (a[i] == a[i + 1]) d[i][i + 1] = 1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> a;
		for (length= 0; a[length]; ++length) {}
		init();
		for (int len = 1; len <= length; ++len) {
			for (int i = 0; i < length; ++i) {
				int j = len - 1 + i;
				if (i - 1 >= 0 && j + 1 < length && d[i][j] && a[i - 1] == a[j + 1]) d[i - 1][j + 1] = 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < length; ++i) {
			for (int j = i; j < length; ++j) {
				if (d[i][j]) {
					if (j - i + 1 > ans) ans = j - i + 1;
				}
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}