#include <iostream>
#include <algorithm>
using namespace std;
int a[101];
int b[101];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) ++ans;
	}
	if (ans == 0) cout << 0 << '\n';
	else cout << ans - 1 << '\n';
}