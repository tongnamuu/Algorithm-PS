#include <iostream>
using namespace std;
#define N 100001
long long a[N];
long long cal(long long k) {
    long long ans = 0;
    for (long long i = 1; i*i <= k; ++i) {
        ans += a[i] * (k / (i*i));
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    long long k; cin >> k;
    for (long long i = 1; i < N; ++i) {
        a[i] = 1;
    }
    for (long long i = 2LL; i < N; ++i) {
        if (a[i] != 1) continue;
        for (long long j = i; j < N; j += i) {
            a[j] *= -i;
        }
        for (long long j = i * i; j < N; j += i * i) {
            a[j] = 0;
        }
    }
    for (long long i = 2; i < N; ++i) {
        if (a[i] == i) a[i] = 1;
        else if (a[i] == -i) a[i] = -1;
        else if (a[i] > 0) a[i] = 1;
        else if (a[i] < 0) a[i] = -1;
    }
    long long s = 1LL;
    long long e = 20000000000LL;
    while (s < e) {
        long long m = (s + e) / 2;
        long long v = cal(m);
        if (v > k) e = m - 1;
        else if (v == k) e = m;
        else s = m + 1;
    }
    cout << e << '\n';
}