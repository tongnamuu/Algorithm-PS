#include <iostream>
#include <algorithm>
using namespace std;
#define N 2000001
int a[1001];
int check[N];
int cnt[N];
int primes[200000];
int pn;
void init() {
    for (long long i = 2; i <= 1999993; ++i) {
        if (check[i]) continue;
        primes[pn++] = i;
        for (long long j = i * i; j <= 1999993; j += i) {
            check[j] = true;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    init();
    int n; cin >> n;
    int max_value = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < pn; ++i) {
        if (primes[i] > a[n - 1]) {
            ans = max(ans, 1);
            break;
        }
        for (int j = 0; j < n; ++j) {
            int temp = ++cnt[a[j] % primes[i]];
            ans = max(ans, temp);
        }
        for (int j = 0; j < n; ++j) {
            cnt[a[j] % primes[i]] = 0;
        }
    }
    cout << ans;
}