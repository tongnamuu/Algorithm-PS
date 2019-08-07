#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int ans = 0;
	for (int i = 0, num; i < n; ++i) {
		cin >> num;
		ans ^= num;
	}
	if (ans == 0) cout << "cubelover";
	else cout << "koosaga";
}