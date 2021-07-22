#include <iostream>
using namespace std;
#define MAXNODE 10000000
struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node nodes[MAXNODE];
int nodeCnt;
Node* newNode(int data) {
    nodes[nodeCnt].data = data;
    nodes[nodeCnt].prev = nullptr;
    nodes[nodeCnt].next = nullptr;
    return &nodes[nodeCnt++];
}


struct List {
    Node* head;
    Node* tail;
    Node* cursor;
    int sz;
    List() {
        init();
    }
    void init() {
        head = newNode(0);
        tail = newNode(0);
        head->next = tail;
        tail->prev = head;
        cursor = head;
        sz = 0;
    }

    void cursorAdd(int data) {
        Node* node = newNode(data);
        node->prev = cursor;
        node->next = cursor->next;
        cursor->next->prev = node;
        cursor->next = node;
        ++sz;
        cursor = node;
    }

    void cursorRemove() {
       cursor->next = cursor->next->next;
        cursor->next->prev = cursor;
        //cursor->prev->next = cursor->next;
        //cursor->next->prev = cursor->prev;
        //cursor = cursor->next;
        --sz;
    }

    void tailAdd(int data) {
        Node* node = newNode(data);
        node->next = tail;
        node->prev = tail->prev;
         tail->prev->next = node;
        tail->prev = node;
        ++sz;
    }

    void setCursor(int x) {
        Node* temp = head;
        int cnt = 0;
        while (temp != tail) {
            if (cnt == x) {
                cursor = temp;
                break;
            }
            ++cnt;
            temp = temp->next;
        }
    }

    void insert(int x, int y) {
        setCursor(x);
        for (int i = 0, k; i < y; ++i) {
            cin >> k;
            cursorAdd(k);
        }
    }

    void del(int x, int y) {
        setCursor(x);
        for (int i = 0; i < y; ++i) {
            cursorRemove();
        }
    }
    void add(int y) {
        for (int i = 0, k; i < y; ++i) {
            cin >> k;
            tailAdd(k);
        }
    }

    void print10() {
        int n = sz < 10 ? sz : 10;
        Node* temp = head->next;
        for (int i = 0; i < n; ++i, temp=temp->next) {
            cout << temp->data << ' ';
        }
        cout << '\n';
    }

};
List list;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    freopen("input.txt", "r", stdin);
    for (int tc = 1; tc <= 10; ++tc) {
        nodeCnt = 0;
        list.init();
        int n; cin >> n;
        list.add(n);
        int cmd; cin >> cmd;
        for (int i = 0; i < cmd; ++i) {
            char c; cin >> c; int x, y;
            if (c == 'I') {
                cin >> x >> y;
                list.insert(x, y);
            }
            else if (c == 'D') {
                cin >> x >> y;
                list.del(x, y);
            }
            else if (c == 'A') {
                cin >> y;
                list.add(y);
            }
        }
        cout << '#' << tc << ' ';
        list.print10();
    }
}