#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c >= 100) cout << "OK" << '\n';
	else {
		if (a < b&&a < c) cout << "Soongsil" << '\n';
		else if (b < a&&b < c) cout << "Korea" << '\n';
		else if (c < a&&c < b) cout << "Hanyang" << '\n';
	}
}