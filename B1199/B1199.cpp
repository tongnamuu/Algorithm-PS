#include <iostream>
using namespace std;
#define N 1001
int a[N][N];
int deg[N];
int n;
void go(int now) {
	for (int i = 1; i <= n; ++i) {
		if (a[now][i] > 0) {
			a[now][i]--;
			a[i][now]--;
			go(i);
		}
	}
	cout << now << ' ';
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			deg[j] += a[i][j];
			deg[i] += a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if ((deg[i] >> 1) & 1) {
			cout << -1;
			return 0;
		}
		if (!deg[i]) {
			cout << -1;
			return 0;
		}
	}
	go(1);
}