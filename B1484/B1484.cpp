#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int G; cin >> G;
	int now = 1;
	int prev = 1;
	bool ans = false;
	while (prev <= now ) {
		int g = now * now - prev * prev;
		if (now - prev == 1 && G < g) break;
		if (g == G) {
			cout << now << '\n';
			now++;
			ans = true;
		}
		else if (g < G) {
			now++;
		}
		else {
			prev++;
		}
	}
	if (!ans) cout << -1 << '\n';
}