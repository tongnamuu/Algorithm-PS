#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define SIZE 200001
int p[SIZE];
vector<int>adj[SIZE];
int a[SIZE];
int d[SIZE][2];
int go(int now, int parent, int turn) {
	if (d[now][turn] != -1) return d[now][turn];
	int& ret = d[now][turn];
	ret = 0;
	for (int next : adj[now]) {
		if (next == parent) continue;
		ret += go(next, now, 0);
	}
	if (!turn) {
		int temp = 0;
		for (int next : adj[now]) {
			temp = max(ret - go(next, now, 0) + go(next, now, 1) + a[now] * a[next], temp);
		}
		ret = max(ret, temp);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 2; i <= n; ++i) {
		cin >> p[i];
		adj[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	cout << go(1, 0, 0);
}