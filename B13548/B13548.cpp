#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 100001
int a[N];
int cnt[N];
int freq[N];
int ans[N];
struct Query {
    int l, r, idx;
};
Query query[N];

void add(int num, int& res) {
    cnt[freq[num]] -= 1;
    freq[num] += 1;
    cnt[freq[num]] += 1;
    res = max(res, freq[num]);
}

void remove(int num, int& res) {
    cnt[freq[num]] -= 1;
    if (cnt[freq[num]] == 0 && freq[num] == res) {
        res = max(0, res - 1);
    }
    freq[num] -= 1;
    if (freq[num] > 0) {
        cnt[freq[num]] += 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int g = (int)sqrt(n);
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> query[i].l >> query[i].r;
        query[i].idx = i;
    }
    sort(query, query + m, [&](const auto& u, const auto& v){
        int f = u.l / g;
        int s = v.l / g;
        if (f == s) {
            return u.r < v.r;
        }
        return f < s;
    });
    int l = 1, r = 0, res = 0;
    for (int i = 0; i < m; ++i) {
        int idx = query[i].idx;
        int query_l = query[i].l;
        int query_r = query[i].r;
        while (query_l < l) {
            l--;
            add(a[l], res);
        }
        while (l < query_l) {
            remove(a[l], res);
            l++;
        }
        while (r < query_r) {
            r++;
            add(a[r], res);
        }
        while (query_r < r) {
            remove(a[r], res);
            r--;
        }
        ans[idx] = res;
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << '\n';
    }
}