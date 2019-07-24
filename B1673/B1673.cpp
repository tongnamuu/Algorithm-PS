#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k; 
	while (cin >> n >> k) {
		int ans = n;
		int dojang = n;
		int temp = dojang / k;
		while (temp) {
			ans += temp;
			dojang = dojang % k;
			dojang += temp;
			temp = dojang / k;
		}
		cout << ans << '\n';
	}
}