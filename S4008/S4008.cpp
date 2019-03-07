#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n; int a[12] = { 0, }; int d[12] = { 0, };
		int k = 0;
		for (int i = 0; i < 4; ++i) {
			int num; cin >> num;
			for (int j = 0; j < num; ++j) d[k++] = i;
		}
		for (int i = 0; i < n; ++i) cin >> a[i];
		int max = -100000001;
		int min = 2147483647;
		do {
			int now = a[0];
			for (int i = 0; i < n - 1; ++i) {
				if (d[i] == 0) now += a[i + 1];
				else if (d[i] == 1) now -= a[i + 1];
				else if (d[i] == 2) now *= a[i + 1];
				else if (d[i] == 3) now /= a[i + 1];
			}
			if (now > max) max = now;
			if (now < min) min = now;
		} while (next_permutation(d, d + n - 1));
		cout << '#' << test_case << ' ' << max - min << '\n';
	}
}