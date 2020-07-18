#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], b[N], n;

void mergesort(int l, int r) {
	if (l >= r) return;
	int m = l + r >> 1;
	mergesort(l, m);
	mergesort(m + 1, r);
	int i = l, j = m + 1, k = l;
	while (i <= m && j <= r) {
		if (a[i] <= a[j]) b[k++] = a[i++];
		else b[k++] = a[j++];
	}
	while (i <= m) b[k++] = a[i++];
	while (j <= r) b[k++] = a[j++];
	for (k = l; k <= r; k++) a[k] = b[k];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	mergesort(1, n);

	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}