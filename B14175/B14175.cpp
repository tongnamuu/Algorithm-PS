#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		getchar();
		string s;
		for (int j = 0; j < m; ++j) {
			char ch = getchar();
			for (int l = 0; l < k; ++l) {
				s += ch;
			}
		}
		for (int l = 0; l < k; ++l) {
			cout << s << '\n';
		}
	}
}