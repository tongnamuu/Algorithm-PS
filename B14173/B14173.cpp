#include <iostream>
using namespace std;
struct rec {
	int x1, y1, x2, y2;
};
int main() {
	rec a, b;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	int x1 = a.x1 > b.x1 ? b.x1 : a.x1;
	int y1 = a.y1 > b.y1 ? b.y1 : a.y1;
	int x2 = a.x2 < b.x2 ? b.x2 : a.x2;
	int y2 = a.y2 < b.y2 ? b.y2 : a.y2;
	int temp = (x2 - x1) > (y2 - y1) ? (x2 - x1) : (y2 - y1);
	cout << temp * temp << '\n';
}