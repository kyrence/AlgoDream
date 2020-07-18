#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], n, t;

int main() {
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	while (t--) {
		int l, r;
		cin >> l >> r;
		cout << a[r] - a[l - 1] << endl;
	}

	return 0;
}