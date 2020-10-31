#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000
#define N 5001
int a[N];
int d[N];
int main() {
    string s; cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        a[i+1] = s[i] - '0';
    }
    if (!a[1]) {
        cout << 0;
        return 0;
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }
    d[0] = 1;
    d[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == 0) {
            if (a[i - 1] != 2 && a[i - 1] != 1) {
                cout << 0;
                return 0;
            }
            d[i - 1] = d[i - 2];
        }
        int val = a[i] + 10 * a[i - 1];
        if(val==10||val==20) d[i] = d[i - 1]; // 10, 20
        else if(val>10 && val < 27) d[i] = d[i - 1] + d[i - 2]; // 11~26사이인 경우
        else d[i] = d[i - 1];
        d[i] %= MOD;
    }
    cout << d[n];
}