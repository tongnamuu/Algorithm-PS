#include <iostream>
using namespace std;
long long fact[21];
bool used[21];
int n;
int nthnum(int r) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			if (cnt == r) {
				used[i] = true;
				return i;
			}
			++cnt;
		}
	}
}
int mincnt(int num) {
	int cnt = 0;
	for (int i = 1; i < num; ++i) {
		if (!used[i]) ++cnt;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	fact[0] = 1;
	for (int i = 1; i <= 20; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	cin >> n;
	int cmd; cin >> cmd;
	if (cmd == 1) {
		long long k; cin >> k;
		k--;
		int cur = n - 1;
		while (true) {
			int div = k / fact[cur];
			k -= div * fact[cur];
			int num = nthnum(div);
			cout << num << ' ';
			if (k == 0) {
				for (int i = 1; i <= n; ++i) {
					if (!used[i]) cout << i << ' ';
				}
				return 0;
			}
			cur--;
		}
	}
	else if (cmd == 2) {
		int cur = n - 1;
		long long ans = 1;
		for (int i = 0, num; i < n; ++i) {
			cin >> num;
			used[num] = true;
			ans += mincnt(num)*fact[cur];
			cur--;
		}
		cout << ans << '\n';
	}
}