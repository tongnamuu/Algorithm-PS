#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int G; cin >> G;
	int now = 1;
	int prev = 1;
	long long x = (long long)(now + prev);
	long long y = (long long)(now - prev);
	bool ans = false;
	while (x <= G && y <= G) {
		if (x*y == G) {
			cout << now << '\n';
			now++;
			ans = true;
		}
		else if (x*y < G) {
			now++;
		}
		else {
			prev++;
		}
		x = (long long)(now + prev);
		y = (long long)(now - prev);
	}
	if (!ans) cout << -1;
}