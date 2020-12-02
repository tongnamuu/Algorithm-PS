#include <iostream>
#include <queue>
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
        if (cur + a[i] <= w) {
            cur += a[i];
            insert_time += 1;
        }
        else {

        }
    }
}