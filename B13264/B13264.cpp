#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int len = s.length();
	vector<int>g(len + 1);
	vector<int>sa(len);
	for (int i = 0; i < len; ++i) {
		g[i] = s[i] - 'a' + 1;
		sa[i] = i;
	}
	for (int d = 1; d  < len; d *= 2) {
		auto cmp = [&](int u, int v) {
			if (g[u] == g[v]) return g[u + d] < g[v + d];
			return g[u] < g[v];
		};
		sort(sa.begin(), sa.end(), cmp);
		vector<int>group(len + 1);
		group[sa[0]] = 0;
		group[len] = -1;
		for (int i = 1; i < len; ++i) {
			if (cmp(sa[i - 1], sa[i])) {
				group[sa[i]] = group[sa[i - 1]] + 1;
			}
			else {
				group[sa[i]] = group[sa[i - 1]];
			}
		}
		g = group;
	}
	for (int i = 0; i < len; ++i) {
		cout << sa[i] << '\n';
	}
}