#include <iostream>
using namespace std;
struct cake {
	int x, y, z;
};
cake a; 
cake c;
int main() {
	cin >> a.x >> a.y >> a.z;
	cin >> c.x >> c.y >> c.z;
	cout << c.x - a.z << ' ' << c.y / a.y << ' ' << c.z - a.x << '\n';
}