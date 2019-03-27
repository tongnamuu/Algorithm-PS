#include <iostream>
using namespace std;
struct queue {
	int data[100001];
	int r = 0;
	int f = 0;
	void push(int n) {
		data[r++] = n;
	}
	void pop() {
		if (r>f) ++f;
	}
	int front(){
		return data[f];
	}
	int size() {
		return r - f;
	}
};
queue q;
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) q.push(i);
	while (q.size()) {
		cout << q.front() << ' ';
		q.pop();
		q.push(q.front());
		q.pop();
	}
}