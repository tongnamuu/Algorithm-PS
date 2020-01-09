#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int p[100001];
int pn;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; 
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		pn = 0;
		p[pn++] = a[0];
		for (int i = 1; i < n; ++i) {
			if (a[i] > p[pn - 1]) {
				p[pn++] = a[i];
			}
			else {
				int index = lower_bound(p, p + pn, a[i]) - p;
				p[index] = a[i];
			}
		}
		cout << pn << '\n';
	}
}