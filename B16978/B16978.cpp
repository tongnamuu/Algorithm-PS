#include <iostream>
#include <vector>
using namespace std;
long long a[100001];
struct Node {
	long long val;
	Node* left;
	Node* right;
};
Node nodePool[50 * 100001];
int nodeCnt;
Node* newNode() {
	return &nodePool[nodeCnt++];
}
void init(Node* node, int start, int end) {
	if (start == end) {
		node->val = a[start];
		return;
	}
	node->left = newNode();
	node->right = newNode();
	init(node->left, start, (start + end) / 2);
	init(node->right, (start + end) / 2 + 1, end);
	node->val = node->left->val + node->right->val;
}
long long query(Node* node, int start, int end, int i, int j) {
	if (start > j || end < i) return 0;
	if (i <= start && end <= j) return node->val;
	return query(node->left, start, (start + end) / 2, i, j) + query(node->right, (start + end) / 2 + 1, end, i, j);
}
void update(Node* prev, Node* cur, int start, int end, int index, long long val) {
	if (index < start || end < index) return;
	if (start == end) {
		cur->val = val;
		return;
	}
	int mid = (start + end) / 2;
	if (index <= mid) {
		cur->right = prev->right;
		cur->left = newNode();
		update(prev->left, cur->left, start, mid, index, val);
	}
	else {
		cur->left = prev->left;
		cur->right = newNode();
		update(prev->right, cur->right, mid + 1, end, index, val);
	}
	cur->val = cur->left->val + cur->right->val;
}
vector<Node*> roots;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	Node* root = newNode();
	init(root, 1, n);
	roots.push_back(root);
	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int index, val; cin >> index >> val;
			root = newNode();
			update(roots.back(), root, 1, n, index, val);
			roots.push_back(root);
		}
		else {
			int ver, start, end;
			cin >> ver >> start >> end;
			cout << query(roots[ver], 1, n, start, end) << '\n';
		}
	}
}