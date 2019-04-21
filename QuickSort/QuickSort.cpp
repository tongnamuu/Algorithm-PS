#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
int a[101];
void qsort(int left, int right) {
	if (left >= right) return;
	int i = left;
	int j = right;
	int p = a[(left + right) / 2];
	while (i <= j) {
		while (a[i] < p)++i;
		while (a[j] > p)--j;
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			++i;
			--j;
		}
	}
	if (left < j) qsort(left, j);
	if (i < right) qsort(i, right);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	srand((unsigned int)time(NULL));
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		a[i] = rand() % 100;
	}
	for (int i = 0; i < n; ++i) cout << a[i] << ' ';
	cout << '\n';
	qsort(0, n - 1);
	cout << "After QuickSort" << '\n';
	for (int i = 0; i < n; ++i) cout << a[i] << ' ';
	cout << '\n';
}