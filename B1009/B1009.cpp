#include <iostream>
using namespace std;
int solve(int a, int b) {
	int n = 1;
	int temp = a;
	while (b) {
		if (b & 1) {
			n *= temp;
			n %= 10;
		}
		temp *= temp;
		temp %= 10;
		b >>= 1;
	}
	return n;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T, a, b; cin >> T;
	while (T--) {
		cin >> a >> b;
		int temp = solve(a, b);
		if (temp == 0) temp = 10;
		cout << temp << '\n';
	}
}