#include <iostream>
using namespace std;
int get2(int a) {
	int ans = 0;
	while (a) {
		a /= 2;
		ans += a;
	}
	return ans;
}
int get5(int a) {
	int ans = 0;
	while (a) {
		a /= 5;
		ans += a;
	}
	return ans;
}
int min(const int &a, const int &b) { return a > b ? b : a; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	int a = n, b = n - m, c = m;
	cout << min(get2(a) - get2(b) - get2(c), get5(a) - get5(b) - get5(c)) << '\n';
}