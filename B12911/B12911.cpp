#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
long long d[11][100001];
long long sum[11];
vector<int>factorization[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		d[1][i] = 1;
		for (int j = i * 2; j <= k; j += i) {
			factorization[j].push_back(i);
		}
	}
	sum[1] = k;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			d[i][j] = sum[i - 1];
			for (int f : factorization[j]) {
				d[i][j] -= d[i - 1][f];
				d[i][j] = (d[i][j] + MOD) % MOD;
			}
			sum[i] += d[i][j];
			sum[i] %= MOD;
		}
	}
	long long ans = 0;
	for(int i = 1; i <= k; ++i) {
		ans += d[n][i];
		ans %= MOD;
	}
	cout << ans;
}