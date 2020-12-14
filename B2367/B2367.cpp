#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define S 0
#define E 301
#define INF 1000000000
#define N 302
struct Edge {
    int to, c;
    Edge* rev;
};
Edge edge[300000];
int edge_cnt = 0;
Edge* newEdge(int to, int c) {
    edge[edge_cnt].to = to;
    edge[edge_cnt].c = c;
    return &edge[edge_cnt++]; 
}
vector<Edge*>adj[N];
void add_edge(int from, int to, int c) {
    Edge* e = newEdge(to, c);
    Edge* v = newEdge(from, 0);
    e->rev = v;
    v->rev = e;
    adj[from].push_back(e);
    adj[to].push_back(v);
}
int level[N];
bool bfs() {
    queue<int>q;
    fill(level, level + N, -1);
    level[0] = 0;
    q.push(S);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto& e : adj[now]) {
            int next = e->to;
            if (level[next] == -1 && e->c > 0) {
                q.push(next);
                level[next] = level[now] + 1;
            }
        }
    }
    return level[E] != -1;
}
int dfs(int now, const int dest, int c) {
    if (now == dest) return c;
    for (auto& e : adj[now]) {
        int next = e->to;
        int nc = min(e->c, c);
        if (level[next] == level[now] + 1 && nc) {
            int f = dfs(next, dest, nc);
            if (f) {
                e->c -= f;
                e->rev->c += f;
                return f;
            }
        }
    }
    return 0;
}
int flow() {
    int ans = 0;
    while (bfs()) {
        int f = dfs(S, E, INF);
        if (!f) break;
        ans += f;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, k, d; cin >> n >> k >> d;
    for (int i = 1, num; i <= d; ++i) {
        cin >> num;
        add_edge(i + 200, E, num);
    }
    for (int i = 1, t, x; i <= n; ++i) {
        cin >> t;
        add_edge(S, i, k);
        while (t--) {
            cin >> x;
            add_edge(i, x + 200, 1);
        }
    }
    cout << flow();
}
