#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool NotPrime[2001];
void getPrime() {
    NotPrime[1] = true;
    for (int i = 2; i <= 2000; ++i) {
        if (!NotPrime[i]) {
            for (int j = i * i; j <= 2000; j += i) {
                NotPrime[j] = 1;
            }
        }
    }
}
int a[51];
int l_cnt;
int b[51];
int r_cnt;
int f;
struct NF {
    vector<int>adj[51];
    void add_edge(int x, int y) {
        adj[x].push_back(y);
    }
    void structGraph(int idx){
        for (int i = 0; i < 51; ++i) adj[i].clear();
        for (int i = 0; i < l_cnt; ++i) {
            for (int j = 0; j < r_cnt; ++j) {
                if (j == idx) continue;
                if (!NotPrime[a[i] + b[j]]) {
                    add_edge(i, j);
                }
            }
        }
    }
    int pred[51];
    bool check[51];
    int dfs(int now) {
        if (now == -1) return 1;
        for (int next : adj[now]) {
            if (!check[next]) {
                check[next] = true;
                if (dfs(pred[next])) {
                    pred[next] = now;
                    return 1;
                }
            }
        }
        return 0;
    }
    int flow(int idx) {
        for (int i = 0; i <= 50; ++i) {
            pred[i] = -1;
        }
        int ans = 0;
        for (int i = 0; i < l_cnt; ++i) {
            fill(check, check + 51, false);
            ans += dfs(i);
        }
        return ans;
    }
};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    getPrime();
    int n; cin >> n;
    cin >> f;
    for (int i = 1, x; i < n; ++i) {
        cin >> x;
        if (f & 1) {
            if(x&1) a[l_cnt++] = x;
            else b[r_cnt++] = x;
        }
        else {
            if (x & 1) b[r_cnt++] = x;
            else a[l_cnt++] = x;
        }
    }
    if (l_cnt + 1 != r_cnt) {
        cout << -1; return 0;
    }
    vector<int>ans;
    for (int i = 0; i < r_cnt; ++i) {
        if (!NotPrime[b[i] + f]) {
            NF n;
            n.structGraph(i);
            int temp = n.flow(i);
            if (temp==l_cnt) {
                ans.push_back(b[i]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    if (!ans.size()) cout << -1;
    else for (int i : ans) cout << i << ' ';
}
