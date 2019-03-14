#include <iostream>
using namespace std;
struct pos {
	int first, second;
};
pos a[3];
int ccw() {
	int temp=0;
	for (int i = 0; i < 3; ++i) {
		temp += a[i].first*a[(i + 1) % 3].second;
		temp -= a[i].second*a[(i + 1) % 3].first;
	}
	if (temp > 0) return 1;
	else if (temp == 0) return 0;
	else return -1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 3; ++i) cin >> a[i].first >> a[i].second;
	cout << ccw() << '\n';
}