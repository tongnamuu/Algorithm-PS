#include <iostream>
#include <vector>
using namespace std;
vector<int>a[100001];
int parent[100001];
void go(int node) {
	for (int next : a[node]) {
		if (parent[next] == 0) {
			parent[next] = node;
			go(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	parent[1] = 1;
	go(1);
	for (int i = 2; i <= n; ++i) cout << parent[i] << '\n';
}