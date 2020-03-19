#include <iostream>
#include <algorithm>
using namespace std;
#define N 100001
struct Query {
	int s, e, k, index;
};
Query q[N];
int ans[N];
pair<int,int> a[N];
int tree[N];
void update(int n, int index, int val) {
	for (int i = index; i <= n; i += i & -i) {
		tree[i] += val;
	}
}
int sum(int index) {
	int ans = 0;
	for (int i = index; i > 0; i -= i & -i) {
		ans += tree[i];
	}
	return ans;
}
int query(int s, int e) {
	return sum(e) - sum(s - 1);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n, [](const auto& u, const auto& v) {
		return u.first > v.first;
	});
	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> q[i].s >> q[i].e >> q[i].k;
		q[i].index = i;
	}
	sort(q, q + m, [](const Query& u,const Query& v) {
		return u.k > v.k;
	});
	for (int i = 0, index = 1; i < m; ++i) {
		while (index <= n && a[index].first > q[i].k) {
			update(n, a[index].second, 1);
			++index;
		}
		ans[q[i].index] = query(q[i].s, q[i].e);
	}
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << '\n';
	}
}