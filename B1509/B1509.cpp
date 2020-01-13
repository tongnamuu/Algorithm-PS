#include <iostream>
#include <string>
#define INF 1000000000
using namespace std;
bool p[2501][2501];
int d[2501];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int n = s.length();
	for (int i = 0; i < n; ++i) {
		p[i][i] = true;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == s[i + 1])
			p[i][i + 1] = true;
	}
	for (int len = 3; len <= n; ++len) {
		for (int i = 0; len - 1 + i < n; ++i) {
			int j = len - 1 + i;
			if (p[i + 1][j - 1] && s[i] == s[j]) p[i][j] = true;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (p[0][i]) {
			d[i] = 1;
			continue;
		}
		d[i] = INF;
		for (int j = 1; j <= i; ++j) {
			if (p[j][i]) {
				if (d[i] > d[j - 1] + 1)
					d[i] = d[j - 1] + 1;
			}
		}
	}
	cout << d[n - 1] << '\n';
}