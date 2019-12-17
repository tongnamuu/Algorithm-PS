#include <iostream>
using namespace std;
int solve(int n, int r, int c) {
	if (n == 1) {
		return 0;
	}
	int nextsize = n / 2;
	if (r < nextsize) {
		if (c < nextsize) {
			return solve(n / 2, r, c);
		}
		else {
			return nextsize*nextsize + solve(n / 2, r, c - nextsize);
		}
	}
	else {
		if (c < nextsize) {
			return 2 * nextsize * nextsize + solve(n / 2, r - nextsize, c);
		}
		else {
			return 3 * nextsize*nextsize + solve(n / 2, r - nextsize, c - nextsize);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, r, c;
	cin >> n >> r >> c;
	cout << solve(1 << n, r, c) << '\n';
}