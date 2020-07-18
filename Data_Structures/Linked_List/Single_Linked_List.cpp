#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int e[N], ne[N], head, idx, t;

inline void add_to_head(int x) {
    e[idx] = x, ne[idx] = head, head = idx++;
}

inline void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

inline void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    cin >> t;
    head = -1; idx = 0;

    while (t--) {
        int x, k; char op;
        cin >> op;
        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        } else if (op == 'D') {
            cin >> k;
            if (!k) head = ne[head];
            else remove(k - 1);
        } else {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    
    for (int i = head; ~i; i = ne[i]) 
        cout << e[i] << " ";
    cout << endl;

    return 0;
}
