#include <iostream>
#include <string>
using namespace std;
int d[1001][1001];
int max(int a, int b) { return a > b ? a : b; }
int max3(int a, int b, int c) {
	return max(max(a, b), c);
}
int main() {
	string s, p; cin >> s >> p;
	int len1 = s.length();
	int len2 = p.length();
	bool find = false;//s가 가로, p가 세로
	for (int i = 0; i < len1; ++i) {
		if (find) d[0][i] = 1;
		if (p[0] == s[i]) {
			d[0][i] = 1;
			find = true;
		}
	}
	find = false;
	for (int i = 0; i < len2; ++i) {
		if (find) d[i][0] = 1;
		if (p[i] == s[0]) {
			find = true;
			d[i][0] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i < len2; ++i) {
		for (int j = 1; j < len1; ++j) {
			d[i][j] = max3(d[i][j - 1], d[i - 1][j], d[i - 1][j - 1] + (s[j] == p[i]));
			ans = max(d[i][j], ans);
		}
	}
	cout << ans << '\n';
}