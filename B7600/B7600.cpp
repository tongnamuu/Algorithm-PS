#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	while (1) {
		char a[251];
		cin.getline(a, 251);
		if (a[0] == '#') break;
		int d[26] = { 0, };
		for (int i = 0; a[i]; ++i) {
			if (a[i] >= 'a'&&a[i] <= 'z') {
				d[a[i] - 'a']++;
			}
			else if (a[i] >= 'A'&&a[i] <= 'Z') {
				d[a[i] - 'A']++;
			}
		}
		int ans = 0;
		for (int i = 0; i < 26; ++i) if (d[i]) ++ans;
		cout << ans << '\n';
	}
}