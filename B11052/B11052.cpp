#include <iostream>
using namespace std;
int p[1001];
int d[1001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> p[i];
	for (int i = 1; i <= n; ++i) {
		int temp = p[i];
		for (int j = 1; j <= i; ++j) {
			if (d[i - j] + p[j] >= temp) {
				temp = d[i - j] + p[j];
			}
		}
		d[i] = temp;
	}
	cout << d[n] << '\n';
}