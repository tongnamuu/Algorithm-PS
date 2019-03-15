#include <iostream>
using namespace std;
int main() {
	int d[10] = { 1,2,3,4,5,1,2,3,4,5 };
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		bool ans = false;
		for (int j = 0; j < 10; ++j) {
			int num; cin >> num;
			if (num != d[j]) ans = true;
		}
		if (!ans) cout << i << '\n';
	}
}