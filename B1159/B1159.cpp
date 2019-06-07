#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	string name;
	int d[26] = { 0, };
	for (int i = 0; i < n; ++i) {
		cin >> name;
		++d[name[0] - 'a'];
	}
	bool findans = false;
	for (int i = 0; i < 26; ++i) {
		if (d[i] >= 5) {
			cout << (char)('a' + i);
			findans = true;
		}
	}
	if (!findans) cout << "PREDAJA" << '\n';
}