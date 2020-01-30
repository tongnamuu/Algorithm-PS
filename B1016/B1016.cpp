#include <iostream>
using namespace std;
bool check[1000001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long min, max; cin >> min >> max;
	for (long long i = 2; i*i <= max; ++i) {
		long long start = i * i - min % (i*i);
		if (start == i * i) start = 0;
		for (long long j = start; j <= max - min; j += i * i) {
			check[j] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i <= max - min; ++i) {
		ans += (check[i] == 0);
	}
	cout << ans;
}