#include <iostream>
using namespace std;
int gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a[101];
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 1; i < n; ++i) {
		int g = gcd(a[0], a[i]);
		cout << a[0] / g << '/' << a[i] / g << '\n';
	}
}