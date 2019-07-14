#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
struct pos {
	int x, y;
};
pos a[1003];
int n, k;
int dist[1003][1003];
int visit[1003];
bool cal(int cur) {
	for (int i = 0; i <= n + 1; ++i) visit[i] = -1;
	queue<int>q;
	q.push(0);
	visit[0] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (visit[now] > k) break;
		for (int i = 0; i <= n + 1; ++i) {
			if (visit[i]==-1 && dist[now][i] <= cur) {
				visit[i] = visit[now] + 1;
				q.push(i);
			}
		}
	}
	return visit[n + 1] != -1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	a[0].x = 0;
	a[0].y = 0;
	a[n + 1].x = 10000;
	a[n + 1].y = 10000;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= n + 1; ++j) {
			double d = sqrt(pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2)) / 10;
			if (d != (int)d) d += 1;
			dist[i][j] = (int)d;
		}
	}
	int start = 0;
	int end = 10000;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (cal(mid)) end = mid - 1;
		else start = mid + 1;
	}
	cout << start << '\n';
}