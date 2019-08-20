#include <iostream>
using namespace std;
char a[101];
int main() {
	int score; cin >> score; cin >> a;
	for (int i = 0; a[i]; ++i) {
		score += (a[i] - 'A');
	}
	cout << score << '\n';
}