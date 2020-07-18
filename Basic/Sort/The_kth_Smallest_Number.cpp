#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N], n, k;

int quicksort(int l, int r, int k) {
	if (l >= r) return a[l];
	int i = l - 1, j = r + 1, m = a[l + rand() % (r - l + 1)];
	while (i < j) {
		do i++; while (a[i] < m);
		do j--; while (a[j] > m);
		if (i < j) swap(a[i], a[j]);
	}

	int p = j - l + 1;
	if (p >= k) return quicksort(l, j, p);
	else return quicksort(j + 1, r, k - p);
}

int main() {
	srand(time(NULL));
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	cout << quicksort(1, n, k) << endl;

	return 0;
}