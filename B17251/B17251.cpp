#include <iostream>
using namespace std;
int a[1000001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int max = 0;
	int maxindex1 = -1, maxindex2 = -1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > max) {
			max = a[i];
			maxindex2 = i;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == max && maxindex1 == -1) {
			maxindex1 = i;
			break;
		}
	}
	if (maxindex1 == n - 1 - maxindex2) cout << 'X' << '\n';
	else if (maxindex1 > n - 1 - maxindex2) cout << 'B' << '\n';
	else cout << 'R' << '\n';
}