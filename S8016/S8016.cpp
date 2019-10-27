#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		long long n; cin >> n;
		n -= 1;
		cout << '#' << test_case << ' ' << 2 * n*n + 1 << ' ' << 2 * (n + 1)*(n + 1) - 1 << '\n';
	}
}