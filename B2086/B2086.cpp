#include <iostream>
#include <vector>
using namespace std;
vector<vector<long long>> multiple(vector<vector<long long>> &a, vector<vector<long long>> &b) {
	vector<vector<long long>> c(2, vector<long long>(2));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			c[i][j] = 0;
			for (int k = 0; k < 2; ++k) {
				c[i][j] += (a[i][k] * b[k][j])%1000000000;
			}
		}
	}
	return c;
}
long long matrixmul (long long n) {
	vector<vector<long long>> a(2, vector<long long>(2)); 
	vector<vector<long long>> temp(2, vector<long long>(2));
	a[0][0] = 1; a[0][1] = 1; a[1][0] = 1; a[1][1] = 0;
	temp[0][0] = 1; temp[0][1] = 1; temp[1][0] = 1; temp[1][1] = 0;
	while (n) {
		if (n & 1) {
			a = multiple(a, temp);
		}
		temp = multiple(temp, temp);
		n >>= 1;
	}
	return a[0][0] % 1000000000;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long a, b;
	cin >> a >> b;
	cout << (matrixmul(b) - matrixmul(a - 1) + 1000000000) % 1000000000 << '\n';
}