#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	map<char, int>map;
	int n; cin >> n;
	string str; cin >> str;
	char ch = 'A';
	for (int i = 0, num; i < n; ++i) {
		cin >> num;
		map[ch++] = num;
	}
	stack<double>s;
	double a, b;
	for (int i = 0; str[i]; ++i) {
		if (str[i] == '*'){ 
			b = s.top(); s.pop();
			a = s.top(); s.pop();
			double k = a * b;
			s.push(k);
		}
		else if (str[i] == '+') {
			b = s.top(); s.pop();
			a = s.top(); s.pop();
			double k = a + b;
			s.push(k);
		}
		else if (str[i] == '-') {
			b = s.top(); s.pop();
			a = s.top(); s.pop();
			double k = a - b;
			s.push(k);
		}
		else if (str[i] == '/') {
			b = s.top(); s.pop();
			a = s.top(); s.pop();
			double k = a / b;
			s.push(k);
		}
		else s.push(map[str[i]]);
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top() << '\n';
}