#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int test_case = 1; test_case <= 10; ++test_case) {
		int t;
		string p, s;
		cin >> t >> p >> s;
		int lenp = p.length();
		int len = s.length();
		int ans = 0;
		for(int i=0;i<=len-lenp;++i){
			bool find = true;
			if (s[i] == p[0]) {
				for (int j = 1; j < lenp; ++j) {
					if (s[i + j] != p[j]) {
						find = false;
						break;
					}
				}
				if (find) ans++;
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}