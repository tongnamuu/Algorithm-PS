#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 100001
vector<int>a[SIZE];
bool check[SIZE]; //방문
int low[SIZE]; // i를 루트로하는 서브트리에서 간선 하나로 갈 수 있는 가장 위에 있는 조상
int num[SIZE]; // 몇 번째로 방문하는지
int p[SIZE]; // 부모
int numbering;
vector<pair<int, int>>ans;
void go(int now) {
	check[now] = true;
	num[now] = ++numbering;
	low[now] = numbering;
	for (int next : a[now]) {
		if (!check[next]) {
			p[next] = now;
			go(next);
			low[now] = min(low[now], low[next]);
			if (low[next] > num[now]) {
				if (now > next) ans.push_back({ next,now });
				else ans.push_back({ now,next });
			}
		}
		else if (p[now] != next) {
			low[now] = min(low[now], num[next]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		sort(a[i].begin(), a[i].end());
	}
	for (int i = 1; i <= n; ++i) {
		if (!check[i]) go(i);
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (auto& x : ans) {
		cout << x.first << ' ' << x.second << '\n';
	}
}