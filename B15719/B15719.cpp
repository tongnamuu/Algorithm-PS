#include <iostream>
using namespace std;
int d[10000001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0, num; i < n; ++i) {
		cin >> num;
		if (d[num]) {
			cout << num << '\n';
			return 0;
		}
		++d[num];
	}
}