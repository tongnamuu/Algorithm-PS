#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
pair<double, double> pos[101];
long double dist(int i, int j) {
	return sqrt((pos[i].first - pos[j].first)*(pos[i].first - pos[j].first) + (pos[i].second - pos[j].second)*(pos[i].second - pos[j].second));
}
struct Edge {
	int from, to;
	long double dist;
	bool operator<(const Edge& a) const {
		return dist < a.dist;
	}
};
Edge edge[10001];
int p[101];
int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}
bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	p[x] = y;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> pos[i].first >> pos[i].second;
		p[i] = i;
	}
	int k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			edge[k].from = i;
			edge[k].to = j;
			edge[k++].dist = dist(i, j);
		}
	}
	sort(edge, edge + k);
	long double ans = 0.0;
	for (int i = 0; i < k; ++i) {
		int x = edge[i].from;
		int y = edge[i].to;
		if (merge(x, y)) {
			ans += edge[i].dist;
		}
	}
	cout.fixed;
	cout.precision(3);
	cout << ans;
}