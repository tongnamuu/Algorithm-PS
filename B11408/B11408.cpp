#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define N 806
#define S 0
#define E 805
#define INF 1000000000
int n, m;

struct Edge {
    int to, cap, cost;
    Edge* rev;
    bool operator<(const Edge& a) const {
        return cost > a.cost;
    }
};
int edgeCnt = 0;
Edge edgePool[200000];
Edge* newEdge(int to, int cap, int cost) {
    Edge& e = edgePool[edgeCnt++];
    e.to = to;
    e.cap = cap;
    e.cost = cost;
    return &e;
}
vector<Edge*>adj[N];
void addEdge(int from, int to, int cap, int cost) {
    Edge* e = newEdge(to, cap, cost);
    Edge* r = newEdge(from, 0, -cost);
    e->rev = r;
    r->rev = e;
    adj[from].push_back(e);
    adj[to].push_back(r);
}
int dist[N];
bool inQ[N];
pair<int, int> from[N];
bool spfa(int& totalCost, int& totalCnt) {
    for (int i = 0; i < N; ++i) dist[i] = INF, inQ[i] = false, from[i].first = from[i].second = -1;
    queue<int>q;
    q.push(S);
    dist[S] = 0;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        inQ[now] = false;
        for (int i = 0; i < adj[now].size();++i) {
            Edge* e = adj[now][i];
            if (e->cap > 0) {
                int next = e->to;
                if (dist[next] > dist[now] + e->cost) {
                    dist[next] = dist[now] + e->cost;
                    from[next] = { now, i };
                    if (!inQ[next]) {
                        q.push(next);
                        inQ[next] = true;
                    }                   
                }
            }
        }
    }
    if (dist[E] == INF) return false;
    for (int x = E; from[x].first != -1; x = from[x].first) {
        adj[from[x].first][from[x].second]->cap -= 1;
        adj[from[x].first][from[x].second]->rev->cap += 1;
    }
    totalCost += dist[E];
    totalCnt += 1;
    return true;
}

void flow() {
    int totalCost = 0;
    int totalCnt = 0;
    while (spfa(totalCost, totalCnt));
    cout << totalCnt << '\n' << totalCost << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        addEdge(S, i, 1, 0);
    }
    for (int i = 401; i <= m + 400; ++i) {
        addEdge(i, E, 1, 0);
    }
    for (int i = 1, a, b, cnt; i <= n; ++i) {
        cin >> cnt;
        while (cnt--) {
            cin >> a >> b;
            addEdge(i, a + 400, INF, b);
        }
    }
    flow();
}
