#include <iostream>
#include <string>
using namespace std;
const string str = "____";
void m(int n) {
    for (int i = 0; i < n; ++i) {
        cout << str;
    }
}
void p(int n, int c) {
    if (n == 0) {
        m(c);
        cout <<"\"����Լ��� ������?\"\n";
        m(c);
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        m(c);
        cout<<"��� �亯�Ͽ���.\n";
        return;
    }
    m(c);
    cout << "\"����Լ��� ������?\"\n";
    m(c);
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    m(c);
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    m(c);
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    p(n - 1, c + 1);
    m(c); 
    cout << "��� �亯�Ͽ���.\n";
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    p(n, 0);
}