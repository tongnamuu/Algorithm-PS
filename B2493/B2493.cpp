#include <iostream>
using namespace std;
struct Data {
	int num;
	int index;
};
struct stack {
	Data data[500001];
	int size = 0;
	void push(int n, int index) {
		data[size].num = n;
		data[size++].index = index;
	}
	void pop() {
		if (size > 0) --size;
	}
	Data top() {
		if (size > 0)
			return data[size - 1];
	}
	bool empty() {
		if (size == 0) return true;
		else return false;
	}
};
stack s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int num;
	cin >> num;
	s.push(num,0);
	cout << 0 << ' ';
	for (int i = 1; i < n; ++i) {
		cin >> num;
		if (num > s.top().num) {
			while (!s.empty()&&s.top().num<num) {
				s.pop();
			}
			if (s.empty()) cout << 0 << ' ';
			else cout << s.top().index+1 << ' ';
			s.push(num, i);
		}
		else if (num <= s.top().num) {
			cout << s.top().index+1 << ' ';
			s.push(num, i);
		}
	}
}