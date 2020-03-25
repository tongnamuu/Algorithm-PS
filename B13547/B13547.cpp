#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 1000001
struct Node {
	int val = 0;
	Node *l, *r;
};
Node  nodePool[5 * N];
int nodeCnt;
Node* newNode() { return &nodePool[nodeCnt++]; }
void init(Node* cur, int s, int e) {
	if (s == e) return;
	cur->l = newNode();
	cur->r = newNode();
	int m = s + e >> 1;
	init(cur->l, s, m);
	init(cur->r, m+1,e);
}
void update(Node* prev, Node* cur, int s, int e, int idx, int val) {
	if (s == e) {
		cur->val = prev->val + val;
		return;
	}
	int m = s + e >> 1;
	if (idx <= m) {
		cur->l = newNode();
		cur->r = prev->r;
		update(prev->l, cur->l, s, m, idx, val);
	}
	else {
		cur->r = newNode();
		cur->l = prev->l;
		update(prev->r, cur->r, m + 1, e, idx, val);
	}
	cur->val = cur->l->val + cur->r->val;
}
int query(Node* prev, Node* cur, int s, int e, int i, int j) {
	if (e<i || s>j) return 0;
	if (i <= s && e <= j) return cur->val - prev->val;
	int m = s + e >> 1;
	return query(prev->l, cur->l, s, m, i, j) + query(prev->r, cur->r, m + 1, e, i, j);
}
vector<Node*>roots;
bool used[N] ;
int pos[N];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	Node* dummy = newNode();
	dummy->l = dummy->r = dummy;
	roots.push_back(dummy);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		if (!used[x]) {
			used[x] = true;
			pos[x] = i;
			Node* root = newNode();
			update(roots.back(), root, 1, N - 1, i, 1);
			roots.push_back(root);
		}
		else {
			Node* temp = newNode();
			update(roots.back(), temp, 1, N - 1, pos[x], -1);
			pos[x] = i;
			Node* root = newNode();
			update(temp, root, 1, N - 1, i, 1);
			roots.push_back(root);
		}
	}
	int Q; cin >> Q;
	while (Q--) {
		int s, e; cin >> s >> e;
		cout << query(roots[s - 1], roots[e], 1, N - 1, s, e) << '\n';
	}
}