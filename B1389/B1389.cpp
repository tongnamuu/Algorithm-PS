#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int>a[101];
int d[101];
int solve(int start) {
	queue<int>q;
	for (int i = 1; i <= n; ++i) d[i] = -1;
	d[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int next : a[now]) {
			if (d[next] == -1) {
				q.push(next);
				d[next] = d[now] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans += d[i];
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0, from, to; i < m; ++i) {
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	int index = 0, ans = 2147483647;
	for (int i = 1; i <= n; ++i) {
		int temp = solve(i);
		if (temp < ans) {
			ans = temp;
			index = i;
		}
	}
	cout << index << '\n';
}