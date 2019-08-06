#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int ans = 0;
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		ans ^= x;
	}
	if (ans == 0) cout << "cubelover" << '\n';
	else cout << "koosaga" << '\n';
}