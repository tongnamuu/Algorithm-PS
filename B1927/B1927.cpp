#include <iostream>
using namespace std;
struct pq {
	int heap[100001];
	int hsize = 0;

	void push(int x) {
		int i = ++hsize;
		for (; heap[i / 2] > x; i /= 2) heap[i] = heap[i / 2];
		heap[i] = x;
	}

	int top() { return hsize == 0 ? 0 : heap[1]; }
	void pop() {
		if (hsize == 0) return;
		int parent = 1, child =2;
		int temp = heap[hsize];
		while (child < hsize) {
			if (child + 1 < hsize&&heap[child] > heap[child + 1]) ++child;
			if (temp < heap[child]) break;
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
		heap[parent] = temp;
		--hsize;
	}
};
pq q;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0, num; i < n; ++i) {
		cin >> num;
		if (num == 0) {
			cout << q.top() << '\n'; q.pop();
		}
		else q.push(num);
	}
}