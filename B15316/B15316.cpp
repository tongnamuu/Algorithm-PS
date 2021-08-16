#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;
#define N 200001
int p[N];
int r[N];
struct trip {
    int x, y, c;
};
stack<trip>st;
int find(int x) {
    if (x == p[x]) return x;
    return find(p[x]);
}
int merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    if (r[x] < r[y]) swap(x, y);
    p[y] = x;
    if (r[x] == r[y]) {
        r[x]++;
        st.push({ x,y,1 });
    }
    else st.push({ x,y,0 });
    return 1;
}
void rollback(int cnt) {
    while (cnt--) {
        trip e = st.top(); st.pop();
        p[e.y] = e.y;
        if (e.c) r[e.x]--;
    }
}
pair<int, int>ans[N];
pair<int, int>q[N];
int cnt[N];
int light[N];
int before[N];
struct Life {
    int idx, s, e;
};
vector<Life> lives;
vector<int> seg[4 * N];
void update(int node, int s, int e, int i, int j, int val) {
    if (e<i || j < s) return;
    if (i <= s && e <= j) {
        seg[node].push_back(val);
        return;
    }
    int m = s + e >> 1;
    update(node * 2, s, m, i, j, val);
    update(node * 2 + 1, m + 1, e, i, j, val);
}

void query(int node, int s, int e) {
    int count = 0;
    for (int i : seg[node]) count += merge(q[i].first, q[i].second);
    if (s == e) {
        int res = (find(ans[s].first) == find(ans[s].second));
        if (find(ans[s].first) == find(ans[s].second)) cout << "YES\n";    
        else cout << "NO\n";
        rollback(count);
        return;
    }
    int m = s + e >> 1;
    query(node * 2, s, m);
    query(node * 2 + 1, m + 1, e);
    rollback(count);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) p[i] = i;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        q[i].first = u;
        q[i].second = v;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> light[i];
    }
    int Q; cin >> Q;
    for (int i = 1, cmd, u, v; i <= Q; ++i) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> u;
            if (light[u]) {
                light[u] = 0;
                int start = cnt[before[u]] + 1;
                int end = cnt[i - 1];
                lives.push_back({ u, start, end });
            }
            else {
                light[u] = 1;
                before[u] = i;
            }
        }
        else {
            cin >> u >> v;
            ans[cnt[i - 1] + 1] = { u,v };
            cnt[i] = 1;
        }
        cnt[i] += cnt[i - 1];
    }
    for (int i = 1; i <= m; ++i) if (light[i]) lives.push_back({ i, cnt[before[i]] + 1, cnt[Q] });
    for (Life& l : lives) update(1, 1, cnt[Q], l.s, l.e, l.idx);
    query(1, 1, cnt[Q]);
}
