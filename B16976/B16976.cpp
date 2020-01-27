#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 100001
vector<int> game[SIZE];
int p[SIZE];
int Rank[SIZE];
int l[SIZE];
int r[SIZE];
int ans[SIZE];
pair<int, int>query_list[SIZE];
vector<int>check[SIZE];
struct UnionFind {
	void init(int n) {
		for (int i = 1; i <= n; ++i) {
			p[i] = i;
			Rank[i] = 0;
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
		if (Rank[x] < Rank[y]) p[x] = y;
		else {
			p[y] = x;
			if (Rank[x] == Rank[y]) Rank[x]++;
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		game[x].push_back(i);//i번 사람이 x번 게임을 구매, game[x]를 구매한 사람의 목록 저장
	}
	UnionFind uf;
	for (int i = 1; i <= m; ++i) {
		l[i] = 1;
		r[i] = q;
		ans[i] = ((game[i].size() == 1) ? 0 : -1);
	}
	for (int i = 1; i <= q; ++i) {
		cin >> query_list[i].first >> query_list[i].second;
	}
	while (true) {
		bool go = true;
		for (int i = 1; i <= m; ++i) {
			if (ans[i] == 0) continue;
			if (l[i] <= r[i]) {
				go = false;
				check[(l[i] + r[i]) / 2].push_back(i);
			}
		}
		if (go) break;
		uf.init(n);
		for (int i = 1; i <= q; ++i) {
			uf.merge(query_list[i].first, query_list[i].second);
			for (int target_game : check[i]) {
				bool connected = true;
				int p = uf.findparent(game[target_game][0]);
				for (int users : game[target_game]) {
					if (uf.findparent(users) != p) {
						connected = false;
						break;
					}
				}
				if (connected) {
					if (ans[target_game] == -1 || ans[target_game] > i) {
						ans[target_game] = i;
					}
					r[target_game] = i - 1;
				}
				else {
					l[target_game] = i + 1;
				}
			}
			check[i].clear();
		}
	}
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << '\n';
	}
}