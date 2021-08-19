#include <iostream>
#include <algorithm>
using namespace std;
double a[4];
#define INVALID 10000000
bool isZero(double x) {
    return abs(x) < 1e-6;
}
bool isAns(double x) {
    return abs(x - 24) < 1e-6;
}
double calc(double x, double y, int c) {
    if (c == 0) return x + y;
    if (c == 1) return x - y;
    if (c == 2) return x * y;
    if (c == 3) return !isZero(y) ? x / y : INVALID;
    return INVALID;
}

bool solve() {
    do {
        double temp, temp1, temp2;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    temp = calc(a[0], a[1], i);
                    temp1 = calc(temp, a[2], j);
                    temp2 = calc(temp1, a[3], k);
                    if (temp != INVALID && temp1 != INVALID && isAns(temp2)) return true;
                    temp = calc(a[0], a[1], i);
                    temp1 = calc(a[2], a[3], k);
                    temp2 = calc(temp, temp1, j);
                    if (temp != INVALID && temp1 != INVALID && isAns(temp2)) return true;
                    temp = calc(a[1], a[2], j);
                    temp1 = calc(a[0], temp, i);
                    temp2 = calc(temp1, a[3], k);
                    if (temp != INVALID && temp1 != INVALID && isAns(temp2)) return true;
                    temp = calc(a[1], a[2], j);
                    temp1 = calc(temp, a[3], k);
                    temp2 = calc(a[0], temp1, i);
                    if (temp != INVALID && temp1 != INVALID && isAns(temp2)) return true;
                    temp = calc(a[2], a[3], k);
                    temp1 = calc(a[0], a[1], i);
                    temp2 = calc(temp1, temp, j);
                    if (temp != INVALID && temp1 != INVALID && isAns(temp2)) return true;
                    temp = calc(a[2], a[3], k);
                    temp1 = calc(a[1], temp, j);
                    temp2 = calc(a[0], temp1, i);
                    if (temp != INVALID && temp1 != INVALID && isAns(temp2)) return true;
                }
            }
        }
    } while (next_permutation(a, a + 4));
    return false;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        sort(a, a + 4);
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
}
