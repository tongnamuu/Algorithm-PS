#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int l, k;
string s;
int cost[26];
int d[2001][2001];
const int INF = 1000000000;
int min(int x, int y) { return x > y ? y : x; }
int go(int start, int end) {
	if (start >= end) return 0;
	if (d[start][end] != -1) return d[start][end];
	if (s[start] == s[end]) d[start][end] = go(start + 1, end - 1);
	else d[start][end] = INF;
	d[start][end] = min(go(start + 1, end) + cost[s[start] - 'a'], d[start][end]);
	d[start][end] = min(go(start, end - 1) + cost[s[end] - 'a'], d[start][end]);
	return d[start][end];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		memset(cost, 0, sizeof(cost));
		memset(d, -1, sizeof(d));
		cin >> l >> k;
		cin >> s;
		for (int i = 0, x, y; i < k; ++i) {
			cin >> x >> y;
			cost[i] = (x > y ? y : x);
		}
		cout << '#' << test_case << ' ' << go(0, l - 1) << '\n';
	}
}