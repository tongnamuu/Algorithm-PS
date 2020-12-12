#include <iostream>
#include <algorithm>
using namespace std;
#define INF 2147483647
int a[12][12];
int map[12][12];
int adj[7][7];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
void dfs(int n, int m, int x, int y, int cnt) {
    map[x][y] = cnt;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == 1 && !map[nx][ny]) {
            dfs(n, m, nx, ny, cnt);
        }
    }
}

void find_adj(const int n, const int m, const int now, int x, int y, int dir, int cnt) {
    if (map[x][y] && map[x][y] != now) {
        if(cnt>=4) adj[map[x][y]][now] = adj[now][map[x][y]] = min({ adj[now][map[x][y]], adj[map[x][y]][now], cnt - 2 });
        return;
    }
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && map[nx][ny] != now) {
        find_adj(n, m, now, nx, ny, dir, cnt + 1);
    }
}
struct Edge {
    int from, to, c;
    bool operator<(const Edge& a) const {
        return c < a.c;
    }
};
Edge edge[36];

int p[7];
struct UnionFind {
    UnionFind() {
        for (int i = 1; i <= 6; ++i) p[i] = i;
    }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    int cnt = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] && !map[i][j]){
                dfs(n, m, i, j, cnt);
                cnt++;
            }
        }
    }
    for (int i = 1; i < cnt; ++i) {
        for (int j = 1; j < cnt; ++j) {
            adj[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int dir = 0; dir < 4; ++dir) {
                if(map[i][j])
                    find_adj(n, m, map[i][j], i, j, dir, 1);
            }
        }
    }
    int edge_cnt = 0;
    for (int i = 1; i < cnt; ++i) {
        for (int j = 1; j < cnt; ++j) {
            if (adj[i][j] == INF) continue;
            edge[edge_cnt++] = { i,j,adj[i][j] };
        }
    }
    sort(edge, edge + edge_cnt);
    UnionFind uf;
    int ans = 0;
    int total = 1;
    for (int i = 0; i < edge_cnt; ++i) {
        if (total == cnt - 1) {
            cout << ans;
            return 0;
        }
        int from = edge[i].from;
        int to = edge[i].to;
        if (uf.merge(from, to)) ans += edge[i].c, ++total;
    }
    cout << -1;    
}
