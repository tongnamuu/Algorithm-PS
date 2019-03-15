#include <iostream>
#include <string>
using namespace std;
bool next_permutation(string &s) {
	int n = s.length();
	int index = n - 1;
	while (index >= 1 && s[index - 1] >= s[index]) --index;
	if (index == 0) return false;
	int ind = n - 1;
	while (s[index - 1] >= s[ind]) --ind;
	char temp = s[ind];
	s[ind] = s[index - 1];
	s[index - 1] = temp;
	ind = n - 1;
	while (index < ind) {
		temp = s[ind];
		s[ind] = s[index];
		s[index] = temp;
		--ind;
		++index;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		if (next_permutation(s)) cout << s << '\n';
		else cout << "BIGGEST" << '\n';
	}
}