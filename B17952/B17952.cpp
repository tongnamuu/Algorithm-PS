#include <iostream>
using namespace std;
#define N 1000001
int time[N];
int score[N];
int zeros[N];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1, cmd; i <= n; ++i) {
		cin >> cmd;
		if (cmd) {
			int s, t; cin >> s >> t;
			score[i] = s;
			time[i] = t - 1;
		}
		else zeros[i] = 1;
	}
	int ans = 0;
	for (int i = n; i > 0; --i) {
		if (score[i]) {
			if (time[i] <= zeros[i]) {
				zeros[i] -= time[i];
				ans += score[i];
			}
			else zeros[i] = 0;
		}
		zeros[i - 1] += zeros[i];
	}
	cout << ans;
}