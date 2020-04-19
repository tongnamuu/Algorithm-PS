#include <iostream>
#include <algorithm>
using namespace std;
int coin[4] = { 1,2,5,7 };
int d[100001];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		d[i] = i;
		for (int j = 0; j < 4; ++j) {
			if (i - coin[j] >= 0) {
				d[i] = min(d[i], d[i - coin[j]] + 1);
			}
		}
	}
	cout << d[n];
}