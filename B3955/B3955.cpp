#include <iostream>
using namespace std;
pair<long long, long long> solve(long long a, long long b) {
	long long k = a, c = b;
	long long x1 = 1, x2 = 0, y1 = 0, y2 = 1;
	long long r, q;
	while (b) {
		r = a % b;
		q = a / b;
		long long temp = x2;
		x2 = x1 - x2 * q;
		x1 = temp;

		temp = y2;
		y2 = y1 - y2 * q;
		y1 = temp;

		a = b;
		b = r;
	}
	if (y1 < 0 || x1 >= 0) {
		y1 += k;
		x1 -= c;
	}
	if (a == 1) return{ -x1,y1 };
	else return { -1,-1 };
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	long long k, c;
	while (T--) {
		cin >> k >> c;
		pair<long long, long long>result = solve(k, c);
		if (result.first != -1 && result.second <= 1000000000) cout << result.second << '\n';
		else cout << "IMPOSSIBLE" << '\n';
	}
}