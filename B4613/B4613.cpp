#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	while (true) {
		string s;
		getline(cin, s);
		if (s == "#") break;
		long long ans = 0;
		for (int i = 0; s[i]; ++i) {
			if (s[i] >= 'A'&&s[i] <= 'Z') {
				ans += (s[i] - 'A' + 1)*(i + 1);
			}
		}
		cout << ans << '\n';
	}
}