#include <iostream>
using namespace std;
#define N 100001
int a[N];
long long tree[N];
void update(int n, int index, long long val) {
	for (int i = index; i <= n; i += i & -i) {
		tree[i] += val;
	}	
}
long long query(int index) {
	long long ans = 0;
	for (int i = index; i > 0; i -= i & -i) {
		ans += tree[i];
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int s, e;long long val; cin >> s >> e >> val;
			update(n, s, val);
			update(n, e + 1, -val);
		}
		else if (cmd == 2) {
			int x; cin >> x;
			cout << (long long)(a[x] + query(x)) << '\n';
		}
	}
}