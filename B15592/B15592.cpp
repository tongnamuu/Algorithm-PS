#include <iostream>
using namespace std;
struct pos {
	int x1, y1, x2, y2;
};
pos a, b;
bool checkrange(int x, int y) {
	if (x >= b.x1&&x <= b.x2) {
		if (y >= b.y1&&y <= b.y2) {
			return true;
		}
		else return false;
	}
	return false;
}
int checkline() {
	if (a.x1 >= b.x1&&a.x1 <= b.x2&&a.x2 >= b.x1&&a.x2 <= b.x2) {
		if (a.y1 <= b.y1) {
			return (b.y1 - a.y1)*(a.x2 - a.x1);
		}
		else return (a.y2-b.y2)*(a.x2 - a.x1);
	}
	else if (a.y1 >= b.y1&&a.y1 <= b.y2&&a.y2 >= b.y1&&a.y2 <= b.y2) {
		if (a.x2 >= b.x2) {
			return (a.y2 - a.y1)*(a.x2 - b.x2);
		}
		else return (a.y2 - a.y1)*(b.x1 - a.x1);
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	int cnt = 0;
	cnt += checkrange(a.x1, a.y1);
	cnt += checkrange(a.x1, a.y2);
	cnt += checkrange(a.x2, a.y1);
	cnt += checkrange(a.x2, a.y2);
	int ans = 0;
	if (cnt == 4) ans = 0;
	else if (cnt == 2) ans = checkline();
	else if (cnt == 0 || cnt == 1) ans = (a.y2 - a.y1)*(a.x2 - a.x1);
	cout << ans << '\n';
}