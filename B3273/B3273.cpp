#include <iostream>
using namespace std;
int a[100001];
int b[100001];
void sort(int s, int e) {
    if (s >= e) return;
    int m = s + e >> 1;
    sort(s, m);
    sort(m + 1, e);
    int i = s, j = m + 1, k = s;
    while (i <= m && j <= e) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        }
        else {
            b[k++] = a[j++];
        }
    }
    while (i <= m) b[k++] = a[i++];
    while (j <= e) b[k++] = a[j++];
    for (int i = s; i <= e; ++i) {
        a[i] = b[i];
    }
}
int binary_search(int s, int e, int v) {
    while (s <= e) {
        int m = s + e >> 1;
        if (a[m] == v) return 1;
        if (a[m] > v) e = m - 1;
        else s = m + 1;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(0, n - 1);
    int x; cin >> x;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += binary_search(0, n - 1, x - a[i]);
    }
    cout << ans / 2;
}