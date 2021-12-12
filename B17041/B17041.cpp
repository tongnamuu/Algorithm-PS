#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct T {
    string cmd;
    int s, e;
};
T a[101];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].cmd >> a[i].s >> a[i].e;
    }
    int x = -1000000000;
    int y = 1000000000;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i].cmd == "on") {
            x -= a[i].e;
            y -= a[i].s;
            if (x < 0) x = 0;
        }
        else if (a[i].cmd == "off") {
            x += a[i].s;
            y += a[i].e;
        }
        else {
            x = max(x, a[i].s);
            y = min(y, a[i].e);
        }
    }
    cout << x << ' ' << y << '\n';

    x = -1000000000;
    y = 1000000000;
    for (int i = 0; i < n; ++i) {
        if (a[i].cmd == "on") {
            x += a[i].s;
            y += a[i].e;
        }
        else if (a[i].cmd == "off") {
             x -= a[i].e;
             y -= a[i].s;
             if (x < 0) x = 0;
        }
        else {
            x = max(x, a[i].s);
            y = min(y, a[i].e);
        }
    }
    cout << x << ' ' << y << '\n';
}