#include <iostream>
#include <memory.h>
using namespace std;
int n;
int a[1001];
int d[1001][1001][2];
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int go(int start, int end, int turn) {
	if (d[start][end][turn] != -1) return d[start][end][turn];
	if (start == end) {
		if (turn) return d[start][end][turn] = a[start];
		else return d[start][end][turn] = 0;
	}
	if (turn) {
		int temp = go(start + 1, end, !turn) + a[start];
		int temp1 = go(start, end - 1, !turn) + a[end];
		return d[start][end][turn] = max(temp, temp1);
	}
	else {
		int temp = go(start + 1, end, !turn);
		int temp1 = go(start, end - 1, !turn);
		return d[start][end][turn] = min(temp, temp1);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		memset(d, -1, sizeof(d));
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		cout << go(0, n - 1, 1) << '\n';
	}
}