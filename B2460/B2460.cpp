#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int ans = 0, cur = 0;
	for (int i = 1, in, out; i <= 10; ++i) {
		cin >> out >> in;
		cur -= out;
		cur += in;
		ans = ans < cur ? cur : ans;
	}
	cout << ans << '\n';
}