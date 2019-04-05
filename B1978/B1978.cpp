#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	bool check[1001] = { false, };
	check[0] = check[1] = true;
	for (int i = 0; i <= 1000; ++i) {
		if (!check[i]) {
			for (int j = i * i; j <= 1000; j += i) check[j] = true;
		}
	}
	int num, ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		if (!check[num]) ++ans;
	}
	cout << ans << '\n';
}