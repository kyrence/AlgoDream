#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, a[N];

void quicksort(int l, int r) {
	if (l >= r) return;

	int i = l - 1, j = r + 1, m = a[l + rand() % (r - l + 1)];
	while (i < j) {
		do i++; while (a[i] < m);
		do j--; while (a[j] > m);
		if (i < j) swap(a[i], a[j]);
	}
	quicksort(l, j);
	quicksort(j + 1, r);
}

int main() {
	srand(time(NULL));
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	quicksort(1, n);

	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}