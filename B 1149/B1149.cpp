#include <iostream>
using namespace std;
struct rgb {
	int r;
	int g;
	int b;
};
int min(int a, int b) { return a > b ? b : a; }
int main() {
	int n;
	cin >> n;
	rgb a[1001];
	for (int i = 0; i < n; ++i) {
		cin >> a[i].r >> a[i].g >> a[i].b;
	}
	int d[1001][3] = { 0, };
	d[0][0] = a[0].r;
	d[0][1] = a[0].g;
	d[0][2] = a[0].b;
	for (int i = 1; i < n; ++i) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i].r;
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i].g;
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i].b;
	}
	cout << min(min(d[n-1][0],d[n-1][1]),d[n-1][2]) << '\n';
}