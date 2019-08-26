#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	if (m >= 45) {
		cout << n << ' ' << m - 45;
	}
	else {
		n -= 1;
		if (n < 0) n += 24;
		m = m + 60 - 45;
		cout << n << ' ' << m;
	}
}