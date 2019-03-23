#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void swap1(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
	return;
}
bool next_permutation1(int a[], int n) {
	int index = n - 1;
	while (index >= 1 && a[index - 1] >= a[index]) index--;
	if (index == 0) return false;
	int ind = n - 1;
	while (a[ind] <= a[index - 1]) ind--;
	swap1(a[index - 1], a[ind]);
	int j = n - 1;
	while (index < j) {
		swap1(a[index], a[j]);
		index++;
		--j;
	}
	return true;
}
int main() {
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		int a[14];
		int b[14] = { 0, };
		for (int i = n - 1; i >= n - 6; --i) b[i] = 1;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<vector<int>>ans;
		do {
			vector<int>now;
			for (int i = 0; i < n; ++i) {
				if (b[i]) {
					now.push_back(a[i]);
				}
			}
			ans.push_back(now);
		} while (next_permutation1(b, n));
		sort(ans.begin(), ans.end());
		for (auto p : ans) {
			for (int i = 0; i < 6; ++i) {
				cout << p[i] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}