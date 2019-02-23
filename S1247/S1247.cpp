#include <iostream>
using namespace std;
struct pos {
	int x, y;
};
bool next_permutation(int a[], int n) {
	int index = n - 1;
	while (index>=1 && a[index - 1] >= a[index]) --index;
	if (index == 0) return false;
	int ind = n - 1;
	while (a[index - 1] >= a[ind]) --ind;
	int temp = a[ind];
	a[ind] = a[index-1];
	a[index-1] = temp;
	ind = n - 1;
	while (index < ind) {
		int temp = a[ind];
		a[ind] = a[index];
		a[index] = temp;
		index++;
		ind--;
	}
	return true;
}
int abs(int x) {
	if (x>0) return x;
	else return -x;
}
int getdistance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n;
		pos a[10];
		int d[10] = { 0, };
		pos com, home;
		cin >> com.x >> com.y >> home.x >> home.y;
		for (int i = 0; i < n; ++i) {
			cin >> a[i].x >> a[i].y;
			d[i] = i;
		}
		int ans = 2147483647;
		do {
			int temp = getdistance(com.x,com.y,a[d[0]].x,a[d[0]].y)+ getdistance(home.x, home.y, a[d[n-1]].x, a[d[n-1]].y);
			for (int i = 1; i < n; ++i) temp+=getdistance(a[d[i - 1]].x, a[d[i - 1]].y, a[d[i]].x, a[d[i]].y);
			if (temp < ans) ans = temp;
		} while (next_permutation(d, n));
		cout << '#' << test_case << ' ' << ans << '\n';
	}
}