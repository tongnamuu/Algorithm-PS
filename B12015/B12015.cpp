#include <iostream>
using namespace std;
int a[1000001];
int p[1000001];
int lower_bound(int q[], int n, int val) {
	int start = 0;
	int end = n;
	while (start < end) {
		int mid = (start + end) / 2;
		if (q[mid] < val) start = mid + 1;
		else end = mid;
	}
	return end;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int pn = 1;
	p[0] = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] > p[pn - 1]) {
			p[pn++] = a[i];
		}
		else {
			int index = lower_bound(p, pn, a[i]);
			p[index] = a[i];
		}
	}
	cout << pn << '\n';
}