#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int d[2][26];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		memset(d, 0, sizeof(d));
		string a, b; cin >> a >> b;
		for (int i = 0; a[i]; ++i) d[0][a[i] - 'a']++;		
		for (int i = 0; b[i]; ++i) d[1][b[i] - 'a']++;
		bool ans = true;
		for (int i = 0; i < 26; ++i) {
			if (d[0][i] != d[1][i]) {
				ans = false;
				break;
			}
		}
		if (ans) cout << "Possible" << '\n';
		else cout << "Impossible" << '\n';
	}
}