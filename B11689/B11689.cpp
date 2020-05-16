#include <iostream>
using namespace std;
#define N 1000001
long long primes[N];
bool c[N] = { false, };
int pn;
void init() {
    for (long long i = 2; i <= N; ++i) {
        if (!c[i]) {
            primes[pn++] = i;
            for (long long j = i * i; j <= N; j += i) {
                c[j] = 1;
            }
        }
    }
}
long long Eulerphi(long long n) {
    int idx = 0;
    long long p = primes[idx], ans = n;
    while (p*p <= n) {
        if (n%p == 0) ans -= ans / p;
        while (n%p == 0) n /= p;
        p = primes[++idx];
    }
    if (n != 1) ans -= ans / n;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    init();
    long long n; cin >> n;
    cout << Eulerphi(n);
}