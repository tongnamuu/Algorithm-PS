#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    long long n; cin >> n;
    if (n % 7 == 2 || n % 7 == 0) cout << "CY";
    else cout << "SK";
}