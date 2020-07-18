#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int q[N], hh, tt = -1, t;

int main() {
    cin >> t;
    while (t--) {
        string op; int x;
        cin >> op;
        if (op == "push") {
            cin >> x;
            q[++tt] = x;
        } else if (op == "empty") puts(hh > tt ? "YES" : "NO");
        else if (op == "query") cout << q[hh] << endl;
        else hh++;
    }

    return 0;
}