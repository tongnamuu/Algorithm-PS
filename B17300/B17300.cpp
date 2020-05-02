#include <iostream>
using namespace std;
int a[10];
int check[10][10];
void init() {
	for (int i = 1; i <= 7; i += 3) {
		check[i][i + 2] = i + 1;
		check[i + 2][i] = i + 1;
	}
	for (int i = 1; i <= 3; ++i) {
		check[i][i + 6] = i + 3;
		check[i + 6][i] = i + 3;
	}
	check[1][9] = 5;
	check[9][1] = 5;
	check[3][7] = 5;
	check[7][3] = 5;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	init();
	int n; cin >> n;
	int prev; cin >> prev; a[prev] = 1;
	for (int i = 1, x; i < n; ++i) {
		cin >> x;
		int t = check[prev][x];
		if (a[x]||(t&&!a[t])) {
			cout << "NO";
			return 0;
		}
		a[x] = 1;
		prev = x;
	}
	cout << "YES";
}