#include <iostream>
using namespace std;
bool check[10];
int abs(int x, int y) { return x > y ? x - y: y - x; }
int cango(int num) {
	if (num == 0) {
		if (check[0]) return 0;
		else return 1;
	}
	int len = 0;
	while (num) {
		if (check[num % 10]) return 0;
		num /= 10;
		++len;
	}
	return len;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0, num; i < m; ++i) {
		cin >> num;
		check[num] = true;
	}
	int ans = abs(100, n);
	for (int i = 0; i <= 1000000; ++i) {
		int len = cango(i);
		if (len) {
			int temp = abs(n, i) + len;
			if (temp < ans) ans = temp;
		}
	}
	cout << ans << '\n';
}