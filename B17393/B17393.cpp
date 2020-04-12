#include <iostream>
#include <algorithm>
using namespace std;
#define N 500001
long long a[N];
long long b[N];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> a[i];
	for (int i = 1; i <= n; ++i) 
		cin >> b[i];
	for (int i = 1; i <= n; ++i) {
		int cnt = upper_bound(b + i, b + n + 1, a[i]) - b - i - 1;
		cout << cnt << ' ';
	}
}