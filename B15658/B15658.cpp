#include <iostream>
using namespace std;
int a[12];
int cmd[4];
int n;
int vmax = -1000000001;
int vmin = 1000000001;
void go(int val, int index) {
	if (index == n) {
		if (val > vmax) vmax = val;
		if (val < vmin) vmin = val;
		return;
	}
	if (cmd[0] > 0) { cmd[0]--; go(val + a[index], index + 1); cmd[0]++;}
	if (cmd[1] > 0) { cmd[1]--; go(val - a[index], index + 1); cmd[1]++;}
	if (cmd[2] > 0) { cmd[2]--; go(val * a[index], index + 1); cmd[2]++;}
	if (cmd[3] > 0) { cmd[3]--; go(val / a[index], index + 1); cmd[3]++;}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n; for (int i = 0; i < n; ++i)cin >> a[i]; for (int i = 0; i < 4; ++i) cin >> cmd[i];
	go(a[0], 1);
	cout << vmax << '\n' << vmin << '\n';
}