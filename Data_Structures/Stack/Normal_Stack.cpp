#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int stk[N], n, q;

int main() {
    cin >> q;
    while (q--) {
        string op; int x;
        cin >> op;
        if (op == "push") {
            cin >> x;
            stk[++n] = x;
        } else if (op == "pop") n--;
        else if (op == "query") cout << stk[n] << endl;
        else puts(n ? "NO" : "YES");
    }

    return 0;
}