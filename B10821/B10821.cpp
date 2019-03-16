#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	int ans = 1;
	for (int i = 0; s[i]; ++i) if (s[i] == ',') ++ans;
	cout << ans << '\n';
}