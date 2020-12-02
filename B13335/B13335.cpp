#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int a[1001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, w, l; cin >> n >> w >> l;
    for (int i = 0; i < n; ++i) cin >> a[i];
    queue<pair<int, int>>q;
    int cur = 0;
    int insert_time = 0;
    for (int i = 0; i < n; ++i) {
        if (cur + a[i] <= l && q.size() < w) {
            cur += a[i];
            q.push({ a[i], insert_time + w });
            insert_time += 1;
        }
        else {
            while (!q.empty()) {
                int now = q.front().first;
                int time = q.front().second;
                q.pop();
                cur -= now;
                insert_time = max(time, insert_time);
                if (cur + a[i] <= l && q.size() < w) {
                    cur += a[i];
                    q.push({ a[i], insert_time + w });
                    insert_time += 1;
                    break;
                }
            }
        }
    }
    while (!q.empty()) {
        insert_time = q.front().second;
        cur -= q.front().first;
        q.pop();
    }
    cout << insert_time + 1;
}
