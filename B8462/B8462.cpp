#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[100001];
long long ans[100001];
int cnt[1000001];
int g;
struct Query {
	int index;
	int left;
	int right;
	bool operator<(const Query& a) const {
		if (this->left/g == a.left/g) return this->right < a.right;
		return this->left/g < a.left/g;
	}
};
Query query[100001];
void add(long long& sum, int num) {
	sum -= (long long)num * cnt[num] * cnt[num];
	cnt[num]++;
	sum += (long long)num * cnt[num] * cnt[num];
}
void remove(long long& sum, int num) {
	sum -= (long long)num * cnt[num] * cnt[num];
	cnt[num]--;
	sum += (long long)num * cnt[num] * cnt[num];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) {
		cin >> query[i].left >> query[i].right;
		query[i].index = i;
	}
	g = (int)sqrt(n);
	sort(query, query + m);
	int l = 1, r = 1;
	long long sum = 0;
	for (int i = 0; i < m; ++i) {
		int index = query[i].index;
		int ql = query[i].left;
		int qr = query[i].right;
		while (l < ql) {
			remove(sum, a[l]);
			l++;
		}
		while (ql < l) {
			l--;
			add(sum, a[l]);
		}
		while (r <= qr) {
			add(sum, a[r]);
			r++;
		}
		while (qr + 1 < r) {
			r--;
			remove(sum, a[r]);
		}
		ans[index] = sum;
	}
	for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
}