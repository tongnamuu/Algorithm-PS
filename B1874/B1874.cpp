#include <iostream>
#include <stack>
#include <string>
using namespace std;
int n;
stack<int>s;
string ans;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	int num;
	int max = 0;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		if (num >= max) {
			for (int i = max + 1; i <= num; ++i) {
				s.push(i);
				ans += "+\n";
			}
			max = num;
			s.pop();
			ans += "-\n";
		}
		if (num < max) {
			while (!s.empty() && s.top() != num) {
				s.pop();
				ans += "-\n";
			}
			if (s.empty()||s.top() != num) {
				cout << "NO" << '\n';
				return 0;
			}
			s.pop();
			ans += "-\n";
		}
	}
	cout << ans << '\n';
}