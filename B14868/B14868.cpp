#include <iostream>
#include <queue>
using namespace std;
int a[2001*2002];
int p[2001 * 2002];
int Rank[2001 * 2002];
int culture[100000];
int n, k;
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
int range(int x, int y) { return x >= 0 && x < n&&y >= 0 && y < n; }
int findparent(int x) {
	if (x == p[x]) return x;
	return p[x] = findparent(p[x]);
}
void merge(int x, int y) {
	x = findparent(x);
	y = findparent(y);
	if (x == y) return;
	p[y] = x;
	if (a[y]) {
		int temp = Rank[x];
		Rank[x] += Rank[y];
		Rank[y] += temp;
	}
}
int solve(queue<int>& q) {
	int time = 1;
	while (1) {
		int R = q.size();
		while (R--) {
			int x = q.front() % n;
			int y = q.front() / n;
			q.pop();
			if (Rank[findparent(x + n * y)] == k) {
				return time;
			}
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (!range(nx, ny)) continue;
				merge(x + n * y, nx + ny * n);
				if (!a[nx+ny*n]) {
					a[nx + ny * n] = time;
					q.push(nx + ny * n);
				}
				for (int dir2 = 0; dir2 < 4; ++dir2) {
					int nnx = nx + dx[dir2];
					int nny = ny + dy[dir2];
					if (!range(nnx, nny)) continue;
					if(a[nnx+nny*n]) merge(nx + ny * n, nnx + nny * n);
				}
			}
		}
		++time;
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	queue<int>q;
	for (int i = 0, u, v; i < k; ++i) {
		cin >> u >> v;
		u--, v--;
		a[u + v * n] = 9;
		culture[i] = u + v * n;
		q.push(culture[i]);
		Rank[culture[i]] = 1;
	}
	for (int i = 0; i <= n * n; ++i) {
		p[i] = i;
	}
	for (int i = 0; i < k; ++i) {
		int x = culture[i] % n;
		int y = culture[i] / n;
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (range(nx, ny) && a[nx + ny * n] > 0) {
				merge(culture[i], nx + ny * n);
			}
		}
	}
	int pa = findparent(culture[0]);
	bool go = true;
	for (int i = 0; i < k; ++i) {
		if (findparent(culture[i]) != pa) {
			go = false; break;
		}
	}
	if (go) cout << 0 << '\n';
	else cout << solve(q);
}