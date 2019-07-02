#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int n, k; cin >> n >> k;
	string ans;
	while (n > 0) {
		int r = n % k;
		if (r < 10) {
			ans += (r + '0');
		}
		else {
			ans += (char)(r - 10 + 'A');
		}
		n /= k;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}