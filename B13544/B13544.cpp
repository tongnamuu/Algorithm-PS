#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100001
struct Node {
	int val = 0;
	Node* left, *right;
};
Node nodePool[30 * N];
int nodeCnt;
Node* newNode() { return &nodePool[nodeCnt++]; }
void update(Node* prev, Node* cur, int s, int e, int idx) {
	if (idx<s || idx>e) return;
	if (s == e) {
		cur->val = 1;
		return;
	}
	int m = s + e >> 1;
	if (idx <= m) {
		cur->left = newNode();
		cur->right = prev->right;
		update(prev->left, cur->left, s, m, idx);
	}
	else {
		cur->right = newNode();
		cur->left = prev->left;
		update(prev->right, cur->right, m + 1, e, idx);
	}
	cur->val = cur->left->val + cur->right->val;
}
int query(Node* prev, Node* cur, int s, int e, int i, int j) {
	if (e < i || j < s) return 0;
	if (i <= s && e <= j) return cur->val - prev->val;
	int m = s + e >> 1;
	return query(prev->left, cur->left, s, m, i, j) + query(prev->right, cur->right, m + 1, e, i, j);
}
pair<int,int> a[100001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n);
	vector<Node*>roots;
	Node* dummy = newNode();
	dummy->left = dummy->right = dummy;
	roots.push_back(dummy);
	for (int i = 1; i <= n; ++i) {
		Node* root = newNode();
		update(roots.back(), root, 1, n, a[i].second);
		roots.push_back(root);
	}
	int m; cin >> m;
	int ans = 0;
	for (int i = 0, x, y, z; i < m; ++i) {
		cin >> x >> y >> z;
		x ^= ans, y ^= ans, z ^= ans;
		int idx = upper_bound(a + 1, a + 1 + n, z, [](int u, pair<int, int>v) {
			return u < v.first;
		}) - a;
		ans = query(roots[idx - 1], roots[n], 1, n, x, y);
		cout << ans << '\n';
	}
}