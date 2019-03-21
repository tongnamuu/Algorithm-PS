#include <iostream>
#include <string>
using namespace std;
const char alp[] = { 'A','B','C','D','E','F','G','H' };
const string a[] = { "000000","001111","010011","011100","100110","101001","110101","111010" };
int wrong(const string &s) {
	for (int i = 0; i < 8; ++i) {
		int w = 0;
		for (int j = 0; j < 6; ++j) {
			if (s[j] != a[i][j]) {
				++w;
			}
		}
		if (w <= 1) {
			return i;
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int len = 6 * n;
	string ans;
	for (int i = 0; i < len; i += 6) {
		string temp = s.substr(i, 6);
		int t = wrong(temp);
		if (t == -1) {
			cout << i / 6 + 1 << '\n';
			return 0;
		}
		else {
			ans += alp[t];
		}
	}
	cout << ans << '\n';
}