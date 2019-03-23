#include <iostream>
#include <string>
using namespace std;
struct stack {
	char a[110];
	int size = 0;
	void push(char n) {
		a[size++] = n;
	}
	bool empty() {
		if (size == 0) return true;
		else return false;
	}
	char top() {
		if (size >= 1)
			return a[size - 1];
		else
			return '*';
	}
	void pop() {
		if (size>0) size--;
	}
};
int main() {
	while (1) {
		stack s;
		string st;
		getline(cin, st);
		if (st == ".") break;
		int len = st.length();
		bool ans = true;
		for (int i = 0; i<len; ++i) {
			if (st[i] == '(' || st[i] == '[')
				s.push(st[i]);
			else if (st[i] == ')') {
				if (s.empty()) {
					ans = false;
					break;
				}
				if (s.top() == '(') {
					s.pop();
				}
				else {
					ans = false;
					break;
				}
			}
			else if (st[i] == ']') {
				if (s.empty()) {
					ans = false;
					break;
				}
				if (s.top() == '[') {
					s.pop();
				}
				else {
					ans = false;
					break;
				}
			}
		}
		if (!s.empty()) ans = false;
		if (ans) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}

}