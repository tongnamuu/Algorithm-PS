#include <iostream>
using namespace std;
#define N 100001
int Query[N];
int p[N];
int SZ[N];
pair<int, int> merge_query[N];
bool execQuery[N];
int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}
long long merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return 0;
	long long temp = (long long)(SZ[x] * SZ[y]);
	if (SZ[x] > SZ[y]) {
		p[y] = x;
		SZ[x] += SZ[y];
	}
	else {
		p[x] = y;
		SZ[y] += SZ[x];
	}
	return temp;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		SZ[i] = 1;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> merge_query[i].first >> merge_query[i].second;
	}
	for (int i = 1; i <= q; ++i) {
		cin >> Query[i];
		execQuery[Query[i]] = 1;
	}
	for (int i = 1; i <= m; ++i) {
		if (execQuery[i]) continue;
		merge(merge_query[i].first, merge_query[i].second);
	}
	long long ans = 0;
	for (int i = q; i >= 1; --i) {
		ans += merge(merge_query[Query[i]].first, merge_query[Query[i]].second);
	}
	cout << ans;
}