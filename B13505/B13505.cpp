#include <iostream>
using namespace std;
struct Trie {
	int children[2];
	bool terminal = false;
};
Trie trie[3300010];
int nodeCnt = 1;
int nextNode() { return ++nodeCnt; }
int max(int a, int b){ return a > b ? a : b; }
int a[33];
void fill(int num) {
	int j = 31;
	a[j--] = -1;
	for (int i = 0; i < 31; ++i) a[i] = 0;
	while(num > 0) {
		a[j--] = num & 1;
		num /= 2;
	}
}
void insert(int node, int * num) {
	if (*num == -1) {
		trie[node].terminal = true;
		return;
	}
	int next = *num & 1;
	int& nextnode = trie[node].children[next];
	if (nextnode == 0) nextnode = nextNode();
	insert(nextnode, num + 1);
}
int XOR(int node, int * num, int val, int pow) {
	int now = *num;
	if (now == -1) return val;
	int next = trie[node].children[1 - now];
	if (next != 0) {
		return XOR(next, num + 1, val + pow, pow / 2);
	}
	else {
		next = trie[node].children[now];
		if (next != 0) {
			return XOR(next, num + 1, val, pow / 2);
		}
		else return val;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int ans = 0;
	for (int i = 0, num; i < n; ++i) {
		cin >> num;
		fill(num);
		int temp = XOR(1, a, 0, 1 << 30);
		insert(1, a);
		ans = max(ans, temp);
	}
	cout << ans << '\n';
}