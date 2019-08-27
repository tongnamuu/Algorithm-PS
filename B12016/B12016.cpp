#include <iostream>
#include <algorithm>
using namespace std;
pair<long long, int>a[100001];
int seg[400004];
void init(int node, int start, int end) {
	if (start == end) seg[node] = 1;
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
}

void update(int node, int start, int end, int index, int val) {
	if (index<start || index>end) return;
	if (start == end) seg[node] += val;
	else {
		update(node * 2, start, (start + end) / 2, index, val);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
}

int query(int node, int start, int end, int i, int j) {
	if (end<i || start>j) return 0;
	if (i <= start && end <= j) return seg[node];
	else return query(node * 2, start, (start + end) / 2, i, j) + query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
long long ans[100000];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);
	init(1, 0, n - 1);
	long long time = 0;
	int prev = 0;
	int k = n;
	for (int i = 0; i < n; ++i) {
		time += (long long)(a[i].first - prev)*k;
		update(1, 0, n - 1, a[i].second, -1);
		ans[a[i].second] = time - query(1, 0, n - 1, a[i].second, n - 1);
		--k;
		prev = a[i].first;
	}
	for (int i = 0; i < n; ++i) cout << ans[i] << '\n';
}