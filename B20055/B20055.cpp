#include <iostream>
using namespace std;
int a[201];
int robot[201];
void rotate(int n) {
    int temp = a[2 * n];
    for (int i = 2 * n; i > 1; --i) {
        a[i] = a[i - 1];
        robot[i] = robot[i - 1];
    }
    robot[1] = 0;
    a[1] = temp;
}
int move_robot(int n) {
    int res = 0;
    robot[n] = 0;
    for (int i = n; i > 0; --i) {
        if (robot[i]==0 && robot[i - 1] == 1 && a[i] > 0) {
            a[i]--;
            if (a[i] == 0) res++;
            robot[i] = 1;
            robot[i - 1] = 0;
        }
    }
    return res;
}
int up_robot(int n) {
    int res = 0;
    if (a[1] > 0 && !robot[1]) {
        a[1]--;
        if (a[1] == 0) res = 1;
        robot[1] = 1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, k; cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < (n << 1); ++i) {
        cin >> a[i + 1];
    }
    int ans = 1;
    while (1) {
        rotate(n);
        cnt += move_robot(n);
        cnt += up_robot(n);
        if (cnt >= k) break;
        ++ans;
    }
    cout << ans;
}
