#include <iostream>
using namespace std;
#define MOD 1000000009
long long d[1001][1001];
void init() {
	d[0][0] = 1;
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			d[i][j] += d[i - 1][j - 1];
			if (i >= 2) { 
				d[i][j] += d[i - 2][j - 1]; 
			}
			if (i >= 3) {
				d[i][j] += d[i - 3][j - 1];
			}
			d[i][j] %= MOD;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	init();
	while (T--) {
		int n, m; cin >> n >> m;
		cout << d[n][m] << '\n';
	}
}