#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 250000
string toString(long long x) {
	string s = "";
	while (x) {
		if (x & 1) s += '1';
		else s += '0';
		x >>= 1;
	}
	reverse(s.begin(), s.end());
	return s;
}
struct Trie {
	int child[2];
	bool end;
	Trie() {
		child[0] = child[1] = -1;
		end = false;
	}
};
Trie trieNode[50 * N];
int nodeCnt = 0;
void insert(int node, const char* s) {
	if (*s == '\0') {
		trieNode[node].end = true;
		return;
	}
	int& nextNode = trieNode[node].child[*s - '0'];
	if (nextNode == -1) nextNode = ++nodeCnt;
	insert(nextNode, s + 1);
}
pair<int, int> go(int node) {
	if (node == -1) return { 0, 0 };
	auto l = go(trieNode[node].child[0]);
	auto r = go(trieNode[node].child[1]);
	int temp = l.first + r.first + 1;
	if (trieNode[node].end || (l.second && r.second)) return { temp, temp };
	else return { temp, l.second + r.second };
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		long long x; cin >> x;
		insert(0, toString(x).c_str() + 1);
	}
	cout << go(0).second;
}