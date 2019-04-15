#include <iostream>
using namespace std;
int a[101][101];
const int INF = 1000000000;
int min(const int& a, const int& b) { return a > b ? b : a; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 0) a[i][j] = INF;
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] == INF) cout << 0 << ' ';
			else cout << 1 << ' ';
		}
		cout << '\n';
	}
}