#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 100010;

int a[N], n, m;

struct seg {
    int lft, rgh;
    ll tag, val;
} tree[N << 2];

inline int lc(int node) { return node << 1; }
inline int rc(int node) { return node << 1 | 1; }

inline void pushup(int node) {
    tree[node].val = tree[lc(node)].val + tree[rc(node)].val;
}

inline void pushdown(int node) {
    ll &val = tree[node].tag;
    if (val) {
        tree[lc(node)].val += (tree[lc(node)].rgh - tree[lc(node)].lft + 1) * val;
        tree[rc(node)].val += (tree[rc(node)].rgh - tree[rc(node)].lft + 1) * val;
        tree[lc(node)].tag += val;
        tree[rc(node)].tag += val;
        val = 0;
    }
}

inline void build(int node, int lft, int rgh) {
    tree[node].lft = lft;
    tree[node].rgh = rgh;
    tree[node].val = tree[node].tag = 0;
    if (lft == rgh) {
        tree[node].val = a[lft];
        return;
    }
    int mid = (lft + rgh) >> 1;
    build(lc(node), lft, mid);
    build(rc(node), mid + 1, rgh);
    pushup(node);
}

inline void update(int node, int lft, int rgh, ll val) {
    if (lft <= tree[node].lft && tree[node].rgh <= rgh) {
        tree[node].val += val * (tree[node].rgh - tree[node].lft + 1);
        tree[node].tag += val;
        return;
    }
    int mid = (tree[node].lft + tree[node].rgh) >> 1;
    pushdown(node);
    if (lft <= mid) update(lc(node), lft, rgh, val);
    if (mid < rgh) update(rc(node), lft, rgh, val);
    pushup(node);
}

inline ll query(int node, int lft, int rgh) {
    if (lft <= tree[node].lft && tree[node].rgh <= rgh) return tree[node].val;
    int mid = (tree[node].lft + tree[node].rgh) >> 1;
    pushdown(node);
    ll res = 0;
    if (lft <= mid) res = query(lc(node), lft, rgh);
    if (mid < rgh) res += query(rc(node), lft, rgh);
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        char c; int l, r; ll v;
        cin >> c >> l >> r;
        if (c == 'C') cin >> v, update(1, l, r, v);
        else cout << query(1, l, r) << endl;
    }
    
    return 0;
}