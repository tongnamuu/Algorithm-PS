#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
	int val = 0;
	int index;
	Node* left;
	Node* right;
};
Node nodePool[100001 * 30];
int nodeCnt;
Node* newNode() { return &nodePool[nodeCnt++]; }
vector<Node*> roots;
void update(Node* prev, Node* cur, int start, int end, int index) {
	if (index < start || end < index) return;
	if (start == end) {
		cur->val = 1;
		cur->index = index;
		return;
	}
	int mid = (start + end) / 2;
	if (index <= mid) {
		cur->right = prev->right;
		cur->left = newNode();
		update(prev->left, cur->left, start, mid, index);
	}
	else {
		cur->left = prev->left;
		cur->right = newNode();
		update(prev->right, cur->right, mid + 1, end, index);
	}
	cur->val = cur->left->val + cur->right->val;
}
int kth(Node* prev, Node* cur, int start, int end, int k) {
	if (start == end) {
		return cur->index;
	}
	else {
		int left = cur->left->val - prev->left->val;
		if (k <= left) return kth(prev->left, cur->left, start, (start + end) / 2, k);
		else return kth(prev->right, cur->right, (start + end) / 2 + 1, end, k - left);
	}
}
int a[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int>b(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin() + 1, b.end());
	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
	}
	Node* root = newNode();
	root->left = root;
	root->right = root;
	root->val = 0;
	roots.push_back(root);
	for (int i = 1; i <= n; ++i) {
		root = newNode();
		update(roots.back(), root, 1, n, a[i]);
		roots.push_back(root);
	}
	for (int i = 0; i < m; ++i) {
		int s, e, k;
		cin >> s >> e >> k;
		cout << b[kth(roots[s-1], roots[e], 1, n, k)] << '\n';
	}
}