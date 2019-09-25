#include <iostream>
using namespace std;
int n;
int postorder[100001];
int inorder[100001];
int position[100001];
void preorder(int inorder_start, int inorder_end, int postorder_start, int postorder_end) {
	if (inorder_start > inorder_end) return;
	if (postorder_start > postorder_end) return;
	int root = postorder[postorder_end];
	int p = position[root];
	cout << root << ' ';
	int post_order_left = p - inorder_start;
	preorder(inorder_start, p - 1, postorder_start, postorder_start + post_order_left - 1);
	preorder(p + 1, inorder_end, postorder_start + post_order_left, postorder_end - 1);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> inorder[i];
	for (int i = 0; i < n; ++i) cin >> postorder[i];
	for (int i = 0; i < n; ++i) {
		position[inorder[i]] = i;
	}
	preorder(0, n - 1, 0, n - 1);
}