#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
#define N 100002
struct Node {
	long long val = 0;
	Node* l;
	Node* r;
};
Node nodePool[60 * N];
int nodeCnt;
Node* newNode() { 
	nodePool[nodeCnt].val = 0LL;
	nodePool[nodeCnt].l = nullptr;
	nodePool[nodeCnt].r = nullptr;
	return &nodePool[nodeCnt++]; 
}
vector<Node*>roots;
vector<int>adj[N];
void dummy_init(Node* cur, int s, int e) {
	if (s == e) return;
	cur->l = newNode();
	cur->r = newNode();
	int m = (s + e) / 2;
	dummy_init(cur->l, s, m);
	dummy_init(cur->r, m + 1, e);
}
Node* update(Node* cur, int s, int e, int idx, int cnt) {
	if (s == e) {
		Node* temp = newNode();
		temp->val = cur->val + cnt;
		return temp;
	}
	int m = s + e >> 1;
	if (idx <= m) {
		Node* temp = newNode();
		temp->l = update(cur->l, s, m, idx, cnt);
		temp->r = cur->r;
		temp->val = temp->l->val + temp->r->val;
		return temp;
	}
	else {
		Node* temp = newNode();
		temp->r = update(cur->r, m + 1, e, idx, cnt);
		temp->l = cur->l;
		temp->val = temp->l->val + temp->r->val;
		return temp;
	}
}
long long query(Node* p, Node* cur, int s, int e, int i, int j) {
	if (e<i || s>j) return 0LL;
	if (i <= s && e <= j) return cur->val - p->val;
	int m = (s + e) / 2;
	return query(p->l, cur->l, s, m, i, j) + query(p->r, cur->r, m + 1, e, i, j);
}
void init() {
	nodeCnt = 0;
	roots.clear();
	Node* dummy = newNode();
	dummy_init(dummy, 1, N - 1);
	roots.push_back(dummy);
	for (int i = 1; i < N; ++i) {
		adj[i].clear();
		roots.push_back(newNode());
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		init();
		int n, m; cin >> n >> m;
		for (int i = 0, x, y; i < n; ++i) {
			cin >> x >> y;
			adj[x + 1].push_back(y + 1);
		}
		for (int i = 1; i < N; ++i) { 
			roots[i]->val = roots[i - 1]->val;
			roots[i]->l = roots[i - 1]->l;
			roots[i]->r = roots[i - 1]->r;
			for (int v :adj[i]) {
				roots[i] = update(roots[i], 1, N - 1, v, 1);
			}
		}
		long long ans = 0LL;
		for (int i = 0, l, r, b, t; i < m; ++i) {
			cin >> l >> r >> b >> t;
			l++, r++, b++, t++;
			ans += query(roots[l - 1], roots[r], 1, N - 1, b, t);
		}
		cout << ans << '\n';
	}
}
