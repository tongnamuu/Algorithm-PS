#include <iostream>
using namespace std;
int main() {
	int x = 100;
	int y = 12010;
	cout << x << ' ' << y << '\n';
	x = (y = (x ^= y) ^ y) ^ x;
	cout << x << ' ' << y << '\n';
}