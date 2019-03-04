#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int p, m, f, c; cin >> p >> m >> f >> c;
		int temp = 0;
		int coupon = m / p * c;
		while (coupon / f) {
			int addchicken = coupon / f;
			temp += addchicken;
			coupon %= f;
			coupon += addchicken * c;
		}
		cout << temp - m / p * c / f << '\n';
	}
}