#include <iostream>
#include <algorithm>
using namespace std;
int month[14] = { 0, 0, 31, 28, 31, 30, 31, 39, 31, 31, 39, 31, 30, 31 };
void init() {
    for (int i = 1; i <= 13; ++i) {
        month[i] += month[i - 1];
    }
}
int info_to_num(int m, int d) {
    return month[m] + d;
}
struct Data {
    int start, end;
    bool operator<(const Data& a) const {
        if (start == a.start) {
            return end < a.end;
        }
        return start < a.start;
    }
};
Data a[100001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    int pn = 0;
    init();
    const int s = info_to_num(3, 1);
    const int e = info_to_num(11, 30);
    for (int i = 0; i < n; ++i) {
        int m1, d1, m2, d2; cin >> m1 >> d1 >> m2 >> d2;
        int start = info_to_num(m1, d1);
        int end = info_to_num(m2, d2);
        if (end < s || start > e) continue;
        a[pn].start = start;
        a[pn++].end = end;
    }
    sort(a, a + pn);
    if (pn == 0) {
        cout << 0;
        return 0;
    }
    int i = 0;
    int prev = -1;
    while (i < pn && a[i].start <= s) {
        prev = max(prev, a[i].end);
        i += 1;
    }
    if (prev == -1) {
        cout << 0;
        return 0;
    }
    int ans = 1;
    while (i < pn && prev <= e) {
        int end = -1;
        while (i < pn && a[i].start <= prev) {
            end = max(end, a[i].end);
            i += 1;
        }
        if (end == -1 && prev <= e) {
            cout << 0;
            return 0;
        }
        prev = end;
        ++ans;
    }
    if (prev > e) cout << ans;
    else cout << 0;
}
