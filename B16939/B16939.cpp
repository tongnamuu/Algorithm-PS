#include <iostream>
using namespace std;
int a[25];
int b[6][8] = {
	{24,22,1,3,5,7,9,11},
	{23, 21,2,4,6,8,10,12},
	{13,14,5,6,17,18,21,22},
	{15,16,7,8,19,20,23,24},
	{3,4,17,19,10,9,16,14},
	{1,2,18,20,12,11,15,13}
};
void rotate1(int d) {
	int x = a[b[d][0]];
	int y = a[b[d][1]];
	a[b[d][0]] = a[b[d][6]];
	a[b[d][1]] = a[b[d][7]];
	a[b[d][6]] = a[b[d][4]];
	a[b[d][7]] = a[b[d][5]];
	a[b[d][4]] = a[b[d][2]];
	a[b[d][5]] = a[b[d][3]];
	a[b[d][2]] = x;
	a[b[d][3]] = y;
}
void rotate2(int d) {
	int x = a[b[d][0]];
	int y = a[b[d][1]];
	a[b[d][0]] = a[b[d][2]];
	a[b[d][1]] = a[b[d][3]];
	a[b[d][2]] = a[b[d][4]];
	a[b[d][3]] = a[b[d][5]];
	a[b[d][4]] = a[b[d][6]];
	a[b[d][5]] = a[b[d][7]];
	a[b[d][6]] = x;
	a[b[d][7]] = y;
}
bool check() {
	for (int i = 1; i <= 21; i+=4) {
		if (!(a[i] == a[i + 1] && a[i + 1] == a[i + 2] && a[i + 2] == a[i + 3])) return false;
	}
	return true;
}
void solve() {
	for (int i = 0; i < 6; ++i) {
		rotate1(i);
		if (check()) {
			cout << 1 << '\n';
			return;
		}
		rotate2(i); rotate2(i);
		if (check()) {
			cout << 1 << '\n';
			return;
		}
		rotate1(i);
	}
	cout << 0 << '\n';
	return;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 24; ++i) cin >> a[i];
	solve();
}