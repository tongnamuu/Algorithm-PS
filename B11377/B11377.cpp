#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define N 2003
#define S 0
#define E 2001
#define D 2002
struct Edge {
    int to, cap;
    Edge* rev;
};
Edge edge[N*N];
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
    level[S] = 0;
    queue<int>q;
    q.push(S);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto p : adj[now]) {
            if (level[p->to] == -1 && p->cap > 0) {
                q.push(p->to);
                level[p->to] = level[now] + 1;
            }
        }
    }
    return level[E] != -1;
}
int work[N];
int dfs(int now, int c) {
    if (now == E) return c;
    for(int& i = work[now];i<adj[now].size();++i){
        int next = adj[now][i]->to;
        int nc = adj[now][i]->cap;
        if (level[next] == level[now] + 1 && nc > 0) {
            int df = dfs(next, min(c, nc));
            if (df > 0) {
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
        while (true) {
            int f = dfs(S, 100000000);
            if (!f) break;
            ans += f;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    add_edge(S, D, k);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        add_edge(S, i, 1);
        add_edge(D, i, 1);
        for (int j = 0; j < x; ++j) {
            int y; cin >> y;
            y += n;
            add_edge(i, y, 1);
        }
    }
    for (int i = 1; i <= m; ++i) {
        add_edge(i + n, E, 1);
    }
    cout << flow();
}