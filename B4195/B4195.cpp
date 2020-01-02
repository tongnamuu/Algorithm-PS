#include <iostream>
#define SIZE 200001*6
using namespace std;
char f1[21];
char f2[21];
struct Trie {
	int children[52];
	int isend;
};
struct Trie trieNode[SIZE];
int nodeCnt;
int namekind;
int nextNode() {
	++nodeCnt;
	for (int i = 0; i < 52; ++i) {
		trieNode[nodeCnt].children[i] = -1;
	}
	trieNode[nodeCnt].isend = 0;
	return nodeCnt;
}
int chartoNum(char ch) {
	if (ch >= 'A'&&ch <= 'Z') return ch - 'A' + 26;
	return ch - 'a';
}
int insert(int node, const char* str) {
	if (*str == 0) {
		if (trieNode[node].isend == 0) {
			++namekind;
			trieNode[node].isend = namekind;
		}
		return trieNode[node].isend;
	}
	int& nextnode = trieNode[node].children[chartoNum(*str)];
	if (nextnode == -1) {
		nextnode = nextNode();
	}
	return insert(nextnode, str + 1);
}
int p[100001];
int Rank[100001];
void init() {
	for (int i = 0; i <= 100000; ++i) {
		p[i] = i;
		Rank[i] = 1;
	}
}
int findparent(int x) {
	if (x == p[x]) return x;
	return p[x] = findparent(p[x]);
}
void merge(int x, int y) {
	x = findparent(x);
	y = findparent(y);
	if (x == y) return;
	p[x] = y;
	int temp = Rank[x];
	Rank[x] += Rank[y];
	Rank[y] += temp;
}
void solve() {
	int n; cin >> n;
	nodeCnt = -1;
	namekind = 0;
	int root = nextNode();
	init();
	for (int i = 0; i < n; ++i) {
		cin >> f1 >> f2;
		int x = insert(root, f1);
		int y = insert(root, f2);
		merge(x, y);
		x = findparent(x);
		cout << Rank[x] << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		solve();
	}
}