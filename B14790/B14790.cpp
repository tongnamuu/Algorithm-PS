#include <iostream>
using namespace std;
bool up(int n) {
	int prev = n % 10;
	n /= 10;
	while (n) {
		int next = n % 10;
		if (next > prev) return false;
		prev = next;
		n /= 10;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	int n;
	for(int tc=1;tc<=T;++tc) {
		cin >> n;
		for (; n; --n) {
			if (up(n)) {
				cout << "Case #" << tc << ": " << n << '\n';
				break;
			}
		}
	}
}