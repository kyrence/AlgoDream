#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], n, f[N], t;

int main() {
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	while (t--) {
		int l, r, c;
		cin >> l >> r >> c;
		f[l] += c;
		f[r + 1] -= c;
	}

	for (int i = 1; i <= n; i++) {
		f[i] += f[i - 1];
		cout << f[i] + a[i] << " ";
	}
	cout << endl;

	return 0;
}

