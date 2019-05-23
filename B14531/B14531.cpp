#include <iostream>
#include <string>
using namespace std;
char a[201][101];
int n, m;
bool check(int index) {
	int spot[4] = { 0, };
	int plain[4] = { 0, };
	for (int i = 0; i < n; ++i) {
		if (a[i][index] == 'A') {
			spot[0] = 1;
		}
		if (a[i][index] == 'C') {
			spot[1] = 1;
		}
		if (a[i][index] == 'G') {
			spot[2] = 1;
		}
		if (a[i][index] == 'T') {
			spot[3] = 1;
		}
	}
	for (int i = n; i < 2*n; ++i) {
		if (a[i][index] == 'A') {
			plain[0] = 1;
		}
		if (a[i][index] == 'C') {
			plain[1] = 1;
		}
		if (a[i][index] == 'G') {
			plain[2] = 1;
		}
		if (a[i][index] == 'T') {
			plain[3] = 1;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		cnt += plain[i] * spot[i];
	}
	return !cnt;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < 2 * n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	for (int j = 0; j < m; ++j) {
		if (check(j)) ++ans;
	}
	cout << ans << '\n';
}