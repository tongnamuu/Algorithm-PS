#include <iostream>
using namespace std;
struct Trie {
	int children[26];
	bool terminal = false;
};
Trie trie[10001 * 500];
int nodeCnt = 1;
int nextNode() { return ++nodeCnt; }
void insert(int node, const char * str) {
	if (*str == '\0') {
		trie[node].terminal = true;
		return;
	}
	int& nextnode = trie[node].children[*str - 'a'];
	if (nextnode == 0) {
		nextnode = nextNode();
	}
	insert(nextnode, str + 1);
}
int search(int node, const char * str) {
	if (node == 0) return false;
	if (*str == 0) return trie[node].terminal;
	return search(trie[node].children[*str - 'a'], str + 1);
}
char a[501];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		insert(1, a);
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		ans += search(1, a);
	}
	cout << ans << '\n';
}