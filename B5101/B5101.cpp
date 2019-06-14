#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	for (int i = 0; s[i]; ++i) {
		cout << (char)('A' + ((s[i] - 'A' + 23) % 26));
	}
}