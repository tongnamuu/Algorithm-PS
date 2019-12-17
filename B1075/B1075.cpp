#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, f; cin >> n >> f;
	n /= 100;
	n *= 100;
	for (int i = n; i < n + 100; ++i) {
		if (i%f == 0) {
			if (i % 100 < 10) {
				cout << 0 << i % 100;
			}
			else cout << i % 100;
			break;
		}
	}
}