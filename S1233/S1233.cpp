#include <iostream>
using namespace std;
struct Tree {
	char data;
	int left = -1;
	int right = -1;
};
int n;
int state;
bool ans;
void inorder(Tree tree[], int index) {
	if (index * 2 <= n) inorder(tree, index * 2);
	if (state == 1) {
		if (tree[index].data >= '0' && tree[index].data <= '9') {
			ans = false;
			return;
		}
	}
	else if (state == 2) {
		if (tree[index].data == '*' || tree[index].data == '-' || tree[index].data == '+' || tree[index].data == '/') {
			ans = false;
			return;
		}
	}
	state = 3 - state;
	//cout << tree[index].data << ' ';
	if (index * 2 + 1 <= n) inorder(tree, index * 2 + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int test_case = 1; test_case <= 10; ++test_case) {
		cin >> n;
		Tree a[201];
		int num;
		char op;
		for (int i = 0; i < n; ++i) {
			cin >> num >> op;
			a[num].data = op;
			if (num * 2 <= n) cin >> a[num].left;
			if (num * 2 + 1 <= n) cin >> a[num].right;
		}
		if (a[1].data >= '0'&&a[1].data <= '9') state = 1;
		else state = 2;
		ans = true;
		inorder(a, 1);
		if (ans) cout << '#' << test_case << ' ' << 1 << '\n';
		else cout << '#' << test_case << ' ' << 0 << '\n';
	}
}