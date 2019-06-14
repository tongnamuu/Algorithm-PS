#include <iostream>
#include <string>
using namespace std;
int main() {
	char s[256];
	while (true) {
		int ans = 0;
		cin.getline(s, 256);
		if (s[0] == '#') break;
		for (int i = 0; s[i]; ++i) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'|| s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')++ans;
		}
		cout << ans << '\n';
	}
	
}