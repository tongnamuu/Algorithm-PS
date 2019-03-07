#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n, cmp);
	int max = 0;
	for (int i = 0; i < n; ++i) {
		if (max < (i + 1)*a[i])
			max = (i + 1)*a[i];
	}
	cout << max << '\n';
}