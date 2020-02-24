#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
#define INF 1000000000
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
string s;
int n;
string p[4];
int pattern_length[4];
bool go[2501][4];
pair<int, int> d[2501][51][1 << 4];

pair<int,int> solve(int index, int curlen, int used) {
	auto& ans = d[index][curlen][used];
	if (used == 15) return ans = { 0,0 };
	if (ans.first != -1) return ans;
	if (index == n) return { INF,-INF };
	ans = solve(index + 1, max(0, curlen - 1), used);
	for (int i = 0; i < 4; ++i) {
		if (used&(1 << i) || !go[index][i]) continue;
		int nextlen = max(0, pattern_length[i] - curlen);
		auto temp = solve(index, max(curlen, pattern_length[i]), used + (1 << i));
		ans = { min(temp.first + nextlen,ans.first),max(temp.second + nextlen,ans.second) };
	}
	return ans;
}
void init() {
	for (int k = 0; k < 4; ++k) {
		int len = pattern_length[k] = p[k].length();
		for (int i = 0; i < n; ++i) {
			bool match = false;
			for (int j = 0; i + j < n &&j < len; ++j) {
				if (s[i + j] != p[k][j]) break;
				if (j == len - 1) match = true;
			}
			if (match) go[i][k] = true;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> s; n = s.length();
	for (int i = 0; i < 4; ++i) cin >> p[i];
	init();
	memset(d, -1, sizeof(d));
	auto ans = solve(0, 0, 0);
	cout << ans.first << ' ' << ans.second;
}