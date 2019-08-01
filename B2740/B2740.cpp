#include <iostream>
using namespace std;
int a[101][101];
int b[101][101];
int c[101][101];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	int r; cin >> m >> r;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < r; ++j) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < r; ++k) {
			for (int j = 0; j < m; ++j) {
				c[i][k]+=a[i][j] * b[j][k];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < r; ++j) {
			cout << c[i][j] << ' ';
		}
		cout << '\n';
	}
}