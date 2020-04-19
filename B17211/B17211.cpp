#include <iostream>
#include <cmath>
using namespace std;
long double p[4];
long double d[101][2];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, s; cin >> n >> s;
	for (int i = 0; i < 4; ++i) {
		cin >> p[i];
	}
	d[0][s] = 1;
	for (int i = 1; i <= n; ++i) {
		d[i][0] = p[0] * d[i - 1][0] + p[2] * d[i - 1][1];
		d[i][1] = p[1] * d[i - 1][0] + p[3] * d[i - 1][1];
	}
	d[n][0] *= 1000;
	d[n][0] = round(d[n][0]);
	d[n][1] *= 1000;
	d[n][1] = round(d[n][1]);
	cout << d[n][0] << '\n' << d[n][1];
}