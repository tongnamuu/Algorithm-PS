#include <iostream>
using namespace std;
#define N 2001
char a[N][N];
int b[N][N];
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= 0 && nx < n&&ny >= 0 && ny < m) {
					b[i][j]++;
				}
			}
		}
	}
	cout << 1 << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'W') {
				if (b[i][j] & 1) {
					cout << 3;
				}
				else {
					cout << 2;
				}
			}
			else if (a[i][j] == 'B') {
				if (b[i][j] & 1) {
					cout << 2;
				}
				else {
					cout << 3;
				}
			}
		}
		cout << '\n';
	}
}