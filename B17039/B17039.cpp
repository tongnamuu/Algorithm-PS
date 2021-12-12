#include <iostream>
#include <algorithm>
int a[3];
using namespace std;
int get_min() {
    if (a[2] - a[0] == 2) {
        return 0;
    }
    if (a[1] - a[0] == 2 || a[2] - a[1] == 2) {
        return 1;
    }
    return 2;
}
int get_max() {
    return max(a[1] - a[0] - 1, a[2] - a[1] - 1);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cout << get_min() << '\n' << get_max();
}
