#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
using mat = vector<vector<long long>>;
mat multiple(const mat& a, const mat& b) {
	int n = a.size();
	mat c(n, vector<long long>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= MOD;
			}
		}
	}
	return c;
}
mat matpow(mat a, int b) {
	int n = a.size();
	mat ret(n, vector<long long>(n));
	for (int i = 0; i < n; ++i) ret[i][i] = 1;
	while (b) {
		if (b & 1) {
			ret = multiple(a, ret);
		}
		a = multiple(a, a);
		b >>= 1;
	}
	return ret;
}
mat map[101];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int p, n, d; cin >> p >> n >> d;
	for (int i = 0; i < p; ++i) {
		map[i] = mat(n, vector<long long>(n));
		int m; cin >> m;
		for (int j = 0, u, v, c; j < m; ++j) {
			cin >> u >> v >> c;
			map[i][u - 1][v - 1] = c;
		}
	}
	mat q = mat(n, vector<long long>(n));
	mat r = mat(n, vector<long long>(n));
	for (int i = 0; i < n; ++i) {
		q[i][i] = 1;
		r[i][i] = 1;
	}
	for (int i = 0; i < p; ++i) {
		q = multiple(q, map[i]);
	}
	q = matpow(q, d / p);
	int rr = d % p;
	for (int i = 0; i < rr; ++i) {
		r = multiple(r, map[i]);
	}
	q = multiple(q, r);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << q[i][j] << ' ';
		}
		cout << '\n';
	}
}