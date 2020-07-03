#include <iostream>
using namespace std;
long long ans[11];
void naive(int n) {
    for (int i = 1; i <= n; ++i) {
        int x = i;
        while (x) {
            ans[x % 10]++;
            x /= 10;
        }
    }
}
long long num_len(int n) {
    if (n == 0) return 1;
    int ans = 0;
    while (n) {
        n /= 10;
        ++ans;
    }
    return ans;
}
long long get_total(int n, int v) {
    long long ans = (long long)(n-v+1)*num_len(n);
    long long r = 1;
    long long x = 9;;
    for (int i = 1; i < v; i *= 10) {
        ans += r * x;
        r++;
        x *= 10;
    }
    return ans;
}
void print() {
    for (int i = 0; i < 10; ++i) {
        cout << ans[i] << ' ';
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
   if (n<=5000) {
        naive(n);
        print();
        return 0;
    }
    int max_n = num_len(n) - 1;
    int val = 1;
    for (int i = 0; i < max_n; ++i) {
        val*= 10;
    }
    long long x = get_total(n, val);
    for (long long i = val, r = max_n; i > 0; i /= 10, --r) {
        long long first_number = n / i;
        long long temp = (i - i / 10) / 9 * r;
        int rest = n % i;
        if (r >= 2) {
            for (int j = 1; j < 10; ++j) {
                ans[j] += first_number * temp;
            }
            for (int m = 1; m < first_number; ++m) {
                ans[m] += i;
            }
            if(first_number) ans[first_number] += rest + 1;
        }
        else {
            naive(n);
            break;
        }
        n -= first_number * i;
    }
    for (int i = 1; i < 10; ++i) x -= ans[i];
    ans[0] = x;
    print();
}