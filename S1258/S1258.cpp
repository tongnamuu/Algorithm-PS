#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[101][101];
bool check[101][101];
int n;
struct mat {
	int size, r, c;
	bool operator<(const mat a) const {
		if (this->size != a.size) return this->size < a.size;
		else return this->r < a.r;
	}
};
mat go(int x, int y) {
	int nx = x;
	int ny = y;
	while (nx<n && a[nx][y]) nx++;
	while (ny<n && a[x][ny]) ny++;
	for (int i = x; i < nx; ++i) for (int j = y; j < ny; ++j) check[i][j] = true;	
	return { (nx - x)*(ny - y),nx - x,ny - y };
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
				check[i][j] = false;
			}
		}
		vector<mat>hubo;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (a[i][j] && !check[i][j]) hubo.push_back(go(i, j));
		sort(hubo.begin(), hubo.end());
		cout << '#' << test_case << ' ' << hubo.size() << ' ';
		for (auto &a : hubo) cout << a.r << ' ' << a.c << ' ';
		cout << '\n';
	}
}