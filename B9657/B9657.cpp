#include <iostream>
using namespace std;
bool d[1001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    d[1] = d[3] = d[4] = 1;
    for (int i = 5; i <= n; ++i) {
        d[i] = false;
        if (i - 1 > 0) {
            if (!d[i - 1]) {
                d[i] = true;
            }
        }
        if (i - 3 > 0) {
            if (!d[i - 3]) {
                d[i] = true;
            }
        }
        if (i - 4 > 0) {
            if (!d[i - 4]) {
                d[i] = true;
            }
        }
    }
    if (d[n]) cout << "SK";
    else cout << "CY";
}