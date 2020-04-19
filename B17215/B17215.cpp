#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Score {
	int x;
	char next = '#';
	char nnext = '#';
};
Score a[15][2];
int getscore(char x) {
	if (x == '-') return 0;
	if (x == '#') return 0;
	if (x == 'S') return 10;
	return x - '0';
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int n = s.length();
	int frame = 1, chance = 0;
	for (int i = 0; i < n; ++i) {
		if (frame > 10) break;
		if (s[i] == '-') {
			s[i] = '0';
			a[frame][chance].x = 0;
			if (chance == 1) ++frame, chance = 0;
			else ++chance;
		}
		else if (s[i] >= '0'&&s[i] <= '9') {
			a[frame][chance].x = s[i]-'0';
			if (chance == 1) ++frame, chance = 0;
			else ++chance;
		}
		else if (s[i] == 'P') {
			a[frame][chance].x = 10 - (s[i - 1] - '0');
			a[frame][chance].next = s[i + 1];
			frame++; chance = 0;
		}
		else if (s[i] == 'S') {
			a[frame][chance].x = 10;
			a[frame][chance].next = s[i + 1];
			a[frame][chance].nnext = s[i + 2];
			frame++; chance = 0;
		}
	}
	int ans = 0;
	for (int i = 1; i <= 10; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (a[i][j].x) {
				ans += a[i][j].x;
			}
			if (a[i][j].nnext == 'P') {
				ans += 10;
			}
			else {
				ans += getscore(a[i][j].next);
				ans += getscore(a[i][j].nnext);
			}
		}
	}
	cout << ans;
}