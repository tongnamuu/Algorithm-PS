#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		long long n; cin >> n;
		if ((n&(n - 1)) == 0) cout << '#' << test_case << ' ' << "YES\n";
		else cout << '#' << test_case << ' ' << "NO\n";
	}
}