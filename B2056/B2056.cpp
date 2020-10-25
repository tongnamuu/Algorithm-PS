#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 100001
int times[N];
int indegree[N];
vector<int>adj[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    priority_queue<pair<int, int>>q;
    for (int i = 1; i <= n; ++i) {
        cin >> times[i] >> indegree[i];
        if (!indegree[i]) {
            q.push({ -times[i], i });
        }
        for (int j = 0, node; j < indegree[i]; ++j) {
            cin >> node;
            adj[node].push_back(i);
        }
    }
    int now, time;
    while (!q.empty()) {
        time = -q.top().first;
        now = q.top().second;
        q.pop();
        for (int next : adj[now]) {
            indegree[next] -= 1;
            if (!indegree[next]) {
                q.push({ -time - times[next], next });
            }
        }
    }
    cout << time;
}
