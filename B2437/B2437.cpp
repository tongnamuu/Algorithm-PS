#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	long long value = 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] > value) {
			cout << value << '\n';
			return 0;
		}
		value += a[i];
	}
	cout << value << '\n';
}