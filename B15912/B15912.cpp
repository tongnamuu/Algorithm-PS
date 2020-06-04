#include <iostream>
#include <algorithm>
using namespace std;
#define N 1001
int n;
long long a[N];
long long b[N];
long long ma[4*N];
long long mb[4*N];
long long d[N];
void init(long long* arr, long long* seg, int node, int s, int e) {
    if (s == e) {
        seg[node] = arr[s];
        return;
    }
    int m = s + e >> 1;
    init(arr, seg, node * 2, s, m);
    init(arr, seg, node * 2 + 1, m + 1, e);
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}
long long query(long long* seg, int node, int s, int e, int i, int j) {
    if (e<i || s>j) return 0;
    if (i <= s && e <= j) return seg[node];
    int m = s + e >> 1;
    return max(query(seg, node * 2, s, m, i, j), query(seg, node * 2 + 1, m + 1, e, i, j));
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    init(a, ma, 1, 1, n);
    init(b, mb, 1, 1, n);
    for (int i = 1; i <= n; ++i) {
        d[i]= query(ma, 1, 1, n, 1, i)*query(mb, 1, 1, n, 1, i);
        for (int j = 1; j <= i; ++j) {
            d[i]=min(d[i],d[j]+ query(ma, 1, 1, n, j + 1, i)*query(mb, 1, 1, n, j + 1, i));
        }
    }
    cout << d[n];
}