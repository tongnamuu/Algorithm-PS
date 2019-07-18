#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, k; cin >> n >> k;
	int onetwo = 0;
	int threefour[2] = { 0, };
	int fivesix[2] = { 0, };
	int ans = 0;
	for (int i = 0, y, s; i < n; ++i) {
		cin >> s >> y;
		if (y == 1 || y == 2) {
			onetwo++;
		}
		else if (y == 3 || y == 4) {
			threefour[s]++;
		}
		else if (y == 5 || y == 6) {
			fivesix[s]++;
		}
	}
	ans += onetwo / k;
	ans += (onetwo % k > 0);
	for (int i = 0; i < 2; ++i) {
		ans += threefour[i] / k;
		ans += (threefour[i] % k > 0);
		ans += fivesix[i] / k;
		ans += (fivesix[i] % k > 0);
	}
	cout << ans << '\n';
}