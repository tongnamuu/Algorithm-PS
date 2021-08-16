#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define N 100001
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
        st.push({ x, y, 1 });
    }
    else st.push({ x, y , 0 });
    return 1;
}

void rollback(int cnt) {
    while (cnt--) {
        trip e = st.top(); st.pop();
        p[e.y] = e.y;
        if (e.c) r[e.x]--;
    }
}

pair<int, int> ans[N];
pair<int, int> q[N];
int cnt[N];
int alive[N];
map<pair<int, int>, int> connected;
struct Life {
    int from, to, s, e;
};
vector<Life> lives;

vector<pair<int, int>>seg[4 * N];
void update(int node, int s, int e, int i, int j, pair<int, int>val) {
    if (e < i || s > j) return;
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
    for (auto& i : seg[node]) count += merge(i.first, i.second);
    if (s == e) {
        int res = (find(ans[s].first) == find(ans[s].second));
        cout << res << '\n';
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
    for (int i = 1, cmd, u, v; i <= m; ++i) {
        cin >> cmd >> u >> v;
        if (u < v) swap(u, v);
        if (cmd == 1) {
            alive[i] = 1;
            connected[{u, v}] = i;
            q[i] = { u,v };
        }
        else if (cmd == 2) {
            alive[connected[{u, v}]] = 0;
            lives.push_back({ u,v, cnt[connected[{u,v}]] + 1, cnt[i - 1] });
        }
        else {
            ans[cnt[i - 1] + 1] = { u,v };
            cnt[i] = 1;
        }
        cnt[i] += cnt[i - 1];
    }
    for (int i = 1; i <= m; ++i) if (alive[i]) lives.push_back({ q[i].first, q[i].second, cnt[i] + 1, cnt[m] });
    for (Life& live : lives) update(1, 1, cnt[m], live.s, live.e, { live.from, live.to });
    query(1, 1, cnt[m]);
}
