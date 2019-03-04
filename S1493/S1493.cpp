#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T;cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int p, q; cin >> p >> q;
		int p1 = 0, q1 = 0;
		while (p1*(p1 + 1) / 2 < p) p1++;
		while (q1*(q1 + 1) / 2 < q) q1++;
		int now = (p1 - 1)*p1 / 2 + 1;
		int cntp = now;
		int px = 1, py = p1 + 1;
		for (int x1 = 1; x1 <= p1; ++x1) {
			if (cntp == p) {
				px = x1;
				py = p1 - x1 + 1;
				break;
			}
			cntp++;
		}
		now = (q1 - 1)*q1 / 2 + 1;
		cntp = now;
		int qx = 1, qy = q1 + 1;
		for (int x1 = 1; x1 <= q1; ++x1) {
			if (cntp == q) {
				qx = x1;
				qy = q1 - x1 + 1;
				break;
			}
			cntp++;
		}
		px += qx;
		py += qy;
		cout << '#' << test_case << ' ' << (2 * px + py - 2)*(py - 1) / 2 + px * (px + 1) / 2 << '\n';
	}
}