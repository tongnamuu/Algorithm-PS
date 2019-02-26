#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s; cin >> s; int len = s.length();
	int d[31][31] = { 0, };
	for (int i = 0; i < len; ++i) {
		d[i][i] = 1;
		if (i + 1 < len) {
			d[i][i + 1] = 2;
			if (s[i] == s[i + 1]) ++d[i][i + 1];
		}
		for (int k = 3; k <= len; ++k) {
			for (int i = 0; i + 1<len; ++i) {
				int j = k + i - 1;
				if (j < len) {
					d[i][j] = d[i + 1][j] + d[i][j - 1] - d[i + 1][j - 1];
					if (s[i] == s[j]) {
						d[i][j] += (d[i + 1][j - 1] + 1);
					}
				}
			}
		}
	}
	cout << d[0][len - 1] << '\n';
}