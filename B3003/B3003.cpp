#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int a[] = { 1,1,2,2,2,8 };
	for (int i = 0; i < 6; ++i) {
		int num;cin >> num;
		cout << a[i] - num << ' ';
	}
}