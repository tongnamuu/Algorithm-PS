#include <iostream>
using namespace std;
int abs(int x, int y) { return x > y ?  x - y : y - x; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
	for (int i = 0, num; i < n;++i){
		for (int j = 0; j < m; ++j) {
			cin >> num;
			if (num == 1) {
				if (x1 == -1) {
					x1 = i, y1 = j;
				}
				else {
					x2 = i, y2 = j;
				}
			}
		}
	}
	cout << abs(x1, x2) + abs(y1, y2) << '\n';
}