#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int>adj[10001];
int d[10001];
int indegree[10001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        adj[v].push_back(u);
        indegree[u]++;
    }
    queue<int>q;
    vector<int>ans;;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
        d[i] = i;
        int temp = 0;
        while (!q.empty()) {
            int now = q.front(); q.pop();
            ++temp;
            for (int next : adj[now]) {
                if (d[next] < i) {
                    d[next] = i;
                    q.push(next);
                }
            }
        }
        if (temp > cnt) {
            cnt = temp;
            ans.clear();
            ans.push_back(i);
        }
        else if (temp == cnt) {
            ans.push_back(i);
        }

    }
    sort(ans.begin(), ans.end());
    for (int i : ans) cout << i << ' ';
}