#include <iostream>
using namespace std;
int a[101];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int ans = n - 1;
	for (int i = n - 1; i >= 1; --i) {
		if (a[i] < a[i + 1]) ans = i - 1;
		else break;
	}
	cout << ans << '\n';
}