#include <iostream>
using namespace std;
#define SIZE 1000001
long long tree[SIZE];
void update(int n, int index, int val) {
	for (int i = index; i <= n; i += i & -i) {
		tree[i] += val;
	}
}
long long query(int index) {
	long long sum = 0;
	for (int i = index; i > 0; i -= i & -i) {
		sum += tree[i];
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0, cmd, p, q; i < m; ++i) {
		cin >> cmd >> p >> q;
		if (cmd == 1) update(n, p, q);
		else cout << query(q) - query(p - 1) << '\n';
	}
}