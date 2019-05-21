#include <iostream>
using namespace std;
int n;
int a[101][101];
bool check[101];
int cnt;
void go(int start, int station) {
	++cnt;
	for (int i = 1; i <= n; ++i) {
		if (i == station) continue;
		if (!check[i] && a[station][i] == 1) {
			check[i] = true;
			go(start, i);
			check[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int from, to; 
		cin >> from >> to;
		a[to][from] = 1;
	}
	int ans = -1;
	for (int i = 1; i <= n; ++i) {
		cnt = 0;
		check[i] = true;
		go(i, i);
		check[i] = false;
		if (cnt == n) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
}