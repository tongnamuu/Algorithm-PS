#include <iostream>
using namespace std;
char a[51][51];
int n;
int ans;
void garocheck(int index) {
	char prev = a[index][0];
	int cnt = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[index][i] == prev) {
			++cnt;
		}
		else {
			if (cnt > ans) ans = cnt;
			cnt = 1;
			prev = a[index][i];
		}
	}
}
void serocheck(int index) {
	char prev = a[0][index];
	int cnt = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i][index] == prev) {
			++cnt;
		}
		else {
			if (cnt > ans) ans = cnt;
			cnt = 1;
			prev = a[i][index];
		}
	}
}
void swapsero(int i, int j) {
	char temp = a[i][j];
	a[i][j] = a[i + 1][j];
	a[i + 1][j] = temp;
}
void swapgaro(int i, int j) {
	char temp = a[i][j];
	a[i][j] = a[i][j + 1];
	a[i][j + 1] = temp;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		garocheck(i); serocheck(i);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i + 1 < n) {
				swapsero(i, j);
				serocheck(j);
				garocheck(i);
				garocheck(i + 1);
				swapsero(i, j);
			}
			if (j + 1 < n) {
				swapgaro(i, j);
				garocheck(i);
				serocheck(j);
				serocheck(j + 1);
				swapgaro(i, j);
			}
		}
	}
	cout << ans << '\n';
}