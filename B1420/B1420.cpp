#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1000000000
#define N 200020
int S;
int E;
char a[100][101];
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
struct Edge {
    int to, cap;
    Edge* rev;
};
Edge edge[10 * N];
int edge_cnt;
Edge* newEdge(int to, int cap) {
    edge[edge_cnt].to = to;
    edge[edge_cnt].cap = cap;
    return &edge[edge_cnt++];
}
vector<Edge*>adj[N];
void add_edge(int from, int to, int cap) {
    Edge* o = newEdge(to, cap);
    Edge* r = newEdge(from, 0);
    o->rev = r;
    r->rev = o;
    adj[from].push_back(o);
    adj[to].push_back(r);
}
int level[N];
bool bfs() {
    fill(level, level + N, -1);
    queue<int>q;
    q.push(S);
    level[S] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto p : adj[now]) {
            int next = p->to;
            int c = p->cap;
            if (level[next] == -1 && c > 0) {
                level[next] = level[now] + 1;
                q.push(next);
            }
        }
    }
    return level[E] != -1;
}
int work[N];
int dfs(int now, int dest, int c) {
    if (now == dest) return c;
    for (int& i = work[now]; i < adj[now].size(); ++i) {
        int next = adj[now][i]->to;
        int nc = adj[now][i]->cap;
        if (level[next] == level[now] + 1 && nc > 0) {
            int df = dfs(next, dest, min(nc, c));
            if (df) {
                adj[now][i]->cap -= df;
                adj[now][i]->rev->cap += df;
                return df;
            }
        }
    }
    return 0;
}
int flow() {
    int ans = 0;
    while (bfs()) {
        fill(work, work + N, 0);
        while (1) {
            int f = dfs(S, E, INF);
            if (!f) break;
            ans += f;
        }
    }
    return ans;
}
int n, m;
int get_now(int x, int y) {
    return m * x + y;
}
int get_next(int v) {
    return v + 10000;
}
bool range(int x, int y) {
    return x >= 0 && x < n&&y >= 0 && y < m;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j) {
            int v_in = get_now(i, j);
            int v_out = get_next(v_in);
            if (a[i][j] == 'K') {
                S = v_in;
                add_edge(v_in, v_out, INF);
                for (int dir = 0; dir < 4; ++dir) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (range(nx, ny)) {
                        if (a[nx][ny] != '#') {
                            int r_in = get_now(nx, ny);
                            add_edge(v_out, r_in, INF);
                        }
                    }
                }
            }
            else if (a[i][j] == 'H') {
                E = v_out;
                add_edge(v_in, v_out, INF);
                for (int dir = 0; dir < 4; ++dir) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (range(nx, ny)) {
                        if (a[nx][ny] != '#') {
                            int r_in = get_now(nx, ny);
                            add_edge(v_out, r_in, INF);
                        }
                    }
                }
            }
            else if (a[i][j] == '.') {
                add_edge(v_in, v_out, 1);
                for (int dir = 0; dir < 4; ++dir) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (range(nx, ny)) {
                        if (a[nx][ny] != '#') {
                            int r_in = get_now(nx, ny);
                            add_edge(v_out, r_in, INF);
                        }
                    }
                }
            }
            else if (a[i][j] == '#') {
                add_edge(v_in, v_out, 0);
            }
        }
    }
    int ans = flow();
    if (ans == INF) ans = -1;
    cout << ans;
}