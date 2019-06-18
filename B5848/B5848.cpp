#include <iostream>
using namespace std;
int a[1001];
bool check[1001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		check[i] = (a[i] == 0);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (check[a[j]])
				check[j] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans += check[i];
	cout << ans << '\n';
}