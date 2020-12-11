#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
bool is_equal(long double a, long double b) { return abs(a - b) <= 1e-4; }
vector<long double> make_ans(long double x1, long double x2, long double x3) {
    vector<long double>res = { x1,x2,x3 };
    sort(res.begin(), res.end());
    x1 = res[0];
    x2 = res[1];
    x3 = res[2];
    if (is_equal(x1, x2) && is_equal(x2, x3) && is_equal(x1,x3)) {
        res.pop_back();
        res.pop_back();
        return res;
    }
    else if (!is_equal(x1, x2) && !is_equal(x2, x3) && !is_equal(x1, x3)) {
        return res;
    }
    else {
        vector<long double>ans;
        ans.push_back(x1);
        ans.push_back(x3);
        return ans;
    }
}
pair<long double, long double> quadratic_equation_solve(long double a, long double b, long double c) {
    long double x1 = (-b + sqrt(b*b - 4 * a*c)) / 2 / a;
    long double x2 = (-b - sqrt(b*b - 4 * a*c)) / 2 / a;
    return { x1,x2 };
}
int determine(long double a, long double b, long double c) {
    long double r = b * b - 4 * a*c;
    if (r == 0) return 1;
    else if (r > 0) return 2;
    else return 0;
}
void solve(long double a, long double b, long double c, long double d, long double r) {
    long double aa = -d - b * r*r - c * r;
    long double bb = -c * r*r - d * r;
    long double cc = -d * r*r;
    int det = determine(aa, bb, cc);
    long double x = (long double)r;
    if (det == 1) {
        long double x1 = -bb / 2 / aa;
        if (is_equal(x1, x)) {
            cout.fixed;
            cout.precision(4);
            cout << x << '\n';
        }
        else {
            cout << fixed;
            cout.precision(4);
            if (x1 > x) cout << x << ' ' << x1 << '\n';
            else cout << x1 << ' ' << x << '\n';
        }
    }
    else if(det==2){
        auto res = quadratic_equation_solve(aa, bb, cc);
        vector<long double> ans = make_ans(res.first, res.second, r);
        cout << fixed;
        cout.precision(4);
        for (long double r : ans) {
            cout << r << ' ';
        }
        cout << '\n';
    }
    else {
        cout << fixed;
        cout.precision(4);
        cout << r << '\n';
    }
}
void solve() {
    long double a, b, c, d; cin >> a >> b >> c >> d;
    long double x = 0;
    if (d != 0) {
        for (long double i = -1000000; i <= 1000000; ++i) {
            if (abs(a*i*i*i + b * i*i + c * i + d) <= 1e-4) {
                x = i;
                break;
            }
        }
        solve(a, b, c, d, x);
    }
    else {
        int det = determine(a, b, c);
        if (det == 2) {
            auto res = quadratic_equation_solve(a, b, c);
            vector<long double> ans = make_ans(res.first, res.second, 0);
            cout << fixed;
            cout.precision(4);
            for (long double r : ans) {
                cout << r << ' ';
            }
            cout << '\n';
        }
        else if (det == 1) {
            long double x = -b / 2 / a;
            if (is_equal(x, 0)) cout << 0.0000 << '\n';
            else {
                cout << fixed;
                cout.precision(4);
                if (x > 0) cout << 0.000 << ' ' << x << '\n';
                else cout << x << ' ' << 0.0000 << '\n';
            }
        }
        else {
            cout << fixed;
            cout.precision(4);
            cout << 0.0000 << '\n';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
