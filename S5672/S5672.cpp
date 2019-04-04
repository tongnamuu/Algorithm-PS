#include <iostream>
using namespace std;
char a[2001];
char b[2001];
char ans[2001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			b[n - 1 - i] = a[i];
		}
		int i = 0, j = 0, size = 0;
		while (size < n) {
			if (a[i] > b[j]) ans[size++] = b[j++];
			else if (a[i] < b[j]) ans[size++] = a[i++];
			else {
				int fx = i;
				int bs = j;
				while (fx >= 0 && fx<n&&bs >= 0 && bs<n&&a[fx] == b[bs]) {
					++fx; ++bs;
				}
				if (fx < n&&bs <  n) {
					if (a[fx] > b[bs]) ans[size++] = b[j++];
					else if (a[fx] < b[bs]) ans[size++] = a[i++];
					else {
						if (size < n) ans[size++] = a[i++];
					}
				}
				else {
					while (size < n) {
						ans[size++] = a[i++];
					}
				}
			}
		}
		cout << '#' << test_case << ' ';
		for (int i = 0; i < n; ++i) cout << ans[i];
		cout << '\n';
	}
}