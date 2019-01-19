#include <iostream>
#include <string>
using namespace std;
struct stack {
	char a[201];
	int size = 0;
	void push(char n) {
		a[size++] = n;
	}
	void pop() {
		if (size > 0)
			a[size---1] = NULL;
	}
	bool empty() {
		if (size == 0) return true;
		else return false;
	}
	char top() {
		if (size > 0)
			return a[size - 1];
	}
};
int main() {
	string s;
	while (1) {
		getline(cin, s);
		if (s == ".") break;
		stack st;
		bool ans = true;
		int len = s.length();
		for (int i = 0; i < len; ++i) {
			if (s[i] == '(' || s[i] == '[')
				st.push(s[i]);
			else if (s[i] == ')') {
				if (st.empty()) {
					ans = false;
					break;
				}
				if (st.top() == '(')
					st.pop();
				else {
					ans = false;
					break;
				}
			}
			else if (s[i] == ']') {
				if (st.empty()) {
					ans = false;
					break;
				}
				if (st.top() == '[')
					st.pop();
				else {
					ans = false;
					break;
				}
			}
			else
				continue;
		}
		if (!st.empty()) ans = false;
		if (ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}