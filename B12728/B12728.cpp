#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
using namespace std;
#define MOD 1000
using Mat = vector<vector<long long>>;
Mat operator*(const Mat& a, const Mat& b) {
	Mat c(2, vector<long long>(2));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				c[i][j] += a[i][k] * b[k][j] + MOD;
				c[i][j] = c[i][j] % MOD;
			}
		}
	}
	return c;
}
Mat matpow(Mat& a, int b) {
	Mat c(2, vector<long long>(2));
	c[0][0] = c[1][1] = 1;
	Mat temp; temp = a;
	while (b) {
		if (b & 1) {
			c = c * temp;
		}
		temp = temp * temp;
		b >>= 1;
	}
	return c;
}
Mat temp = { {6,-4},{1,0} };
void solve(){
	int n; cin >> n;
	assert(n >= 2);
	Mat a = matpow(temp, n - 2);
	int ans = (28 * a[0][0] + 6 * a[0][1] - 1) % MOD;
	cout << setfill('0') << setw(3) << ans << '\n';
}	
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cout << "Case #" << tc << ": ";
		solve();
	}
}