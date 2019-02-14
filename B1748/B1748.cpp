#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;
	int temp = n;
	int len = 0;
	while (temp) {
		temp /= 10;
		++len;
	}
	int ans = 0;
	int start = 1;
	int end = 10 * start;
	for (int i = 1; i < len; ++i) {
		ans+=(end - start)*i;
		start *= 10;
		end *= 10;
	}
	ans += (n - start + 1)*len;
	cout << ans << '\n';
}