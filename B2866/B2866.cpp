#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char a[1001][1001];
int r, c;
string str[1001];
bool stringcmp(string& s1, string& s2) {
	if (s1 == s2) return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> r >> c; for (int i = 0; i < r; ++i) cin >> a[i];
	for (int i = 0; i < c; ++i) {
		for (int j = r-1; j >=0; --j)
			str[i] += a[j][i];
	}
	sort(str, str + c);
	int ans = 0;
	for (int i = 1; i < c; ++i) {
		int cnt = 0;
		for (int j = 0; j < r && str[i - 1][j] == str[i][j]; ++j) {
			++cnt;
		}
		if (cnt > ans) ans = cnt;
	}
	cout << r - 1 - ans << '\n';
}