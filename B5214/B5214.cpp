#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int>a[120001];
int d[120001];
int main() {
	int n, m, k;
	cin >> n >> k >> m;
	int node = n + 1;
	for (int i = 0, x; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> x;
			a[node].push_back(x);
			a[x].push_back(node);
		}
		++node;
	}
	queue<int>q;
	q.push(1);
	d[1] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int next : a[now]) {
			if (d[next] == 0) {
				q.push(next);
				d[next] = d[now] + (next <= n);
			}
		}
	}
	if (d[n] == 0) cout << -1 << '\n';
	else cout << d[n] << '\n';
}