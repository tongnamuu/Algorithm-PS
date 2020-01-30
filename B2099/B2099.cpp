#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> mul(const vector<vector<int>>& a, const vector<vector<int>>& b) {
	int n = a.size();
	vector<vector<int>>c(n, vector<int>(n, 0));
	n--;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				c[i][k] += a[i][j] * b[j][k];
			}
		}
	}
	return c;
}
vector<vector<int>> pow(const vector<vector<int>>& a, int k) {
	vector<vector<int>>temp = a;
	vector<vector<int>>ans(a.size(),vector<int>(a.size(),0));
	for (int i = 1; i < a.size(); ++i) ans[i][i] = 1;
	while (k) {
		if (k & 1) {
			ans = mul(ans,temp);
		}
		temp = mul(temp, temp);
		k >>= 1;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k, m; cin >> n >> k >> m;
	vector<vector<int>>a(n + 1, vector<int>(n + 1, 0));
	for (int i = 1, x, y; i <= n; ++i) {
		cin >> x >> y;
		a[i][x] = 1;
		a[i][y] = 1;
	}
	a = pow(a, k);
	while (m--) {
		int x, y; cin >> x >> y;
		if (a[x][y]) cout << "death" << '\n';
		else cout << "life" << '\n';
	}
}