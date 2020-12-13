#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 1000001
vector<int>adj[N];
int d[N][2];
int solve(int now, int p, int is_early) {
    int& ret = d[now][is_early];
    if (ret != -1) return ret;
    if (!is_early) {
        ret = 0;
        for (int next : adj[now]) {
            if (next == p) continue;
            ret += solve(next, now, 1);
        }
        return ret;
    }
    else {
        ret = 1;
        for (int next : adj[now]) {
            if (next == p) continue;
            ret += min(solve(next, now, 1), solve(next, now, 0));
        }
        return ret;
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    memset(d, -1, sizeof(d));
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << min(solve(1, -1, 0), solve(1, -1, 1));
}
