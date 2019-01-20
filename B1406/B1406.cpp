#include <iostream>
using namespace std;
struct stack {
	char data[600001];
	int size = 0;
	void push(char c) {
		data[size++] = c;
	}
	void pop() {
		--size;
	}
	char top() {
		if (size>0)  return data[size - 1];
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char a[600001];
	stack left;
	stack right;
	cin >> a;
	int len = 0;
	while (a[len]) len++;
	for (int i = 0; i<len; ++i) {
		left.push(a[i]);
	}
	int T;
	cin >> T;
	while (T--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if (left.size>0) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (cmd == 'D') {
			if (right.size>0) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (cmd == 'B') {
			if (left.size>0) {
				left.pop();
			}
		}
		else if (cmd == 'P') {
			char ch;
			cin >> ch;
			left.push(ch);
		}
	}
	len = 0;
	for (int i = 0; len<left.size; ++i) {
		a[len++] = left.data[i];
	}
	for (int i = right.size - 1; i >= 0; --i) {
		a[len++] = right.data[i];
	}
	for (int i = 0; i<len; ++i) cout << a[i];
}