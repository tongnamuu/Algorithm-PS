#include <iostream>
using namespace std;
int ans;
int getlength(int num) {
	if (num == 0) return 1;
	int len = 0;
	while (num) {
		num /= 10;
		len++;
	}
	return len;
}
int ten[] = { 10,100,1000,10000,100000,1000000 };
void go(int num, int turn) {
	if (num < 10) {
		if (turn > ans) ans = turn;
		return;
	}
	int len = getlength(num) - 1;
	for (int i = 1; i < (1 << len); ++i) {
		int temp = 1;
		int now = num;
		for (int j = len - 1; j >= 0; --j) {
			if (i&(1 << j)) {
				temp *= (now / ten[j]);
				now %= ten[j];
			}
		}
		go(temp*now, turn + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n;
		ans = 0;
		go(n, 0);
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}