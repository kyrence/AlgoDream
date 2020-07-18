#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m, t, a[N][N], f[N][N];

int main() {
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	while (t--) {
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		f[x1][y1] += c;
		f[x2 + 1][y1] -= c;
		f[x1][y2 + 1] -= c;
		f[x2 + 1][y2 + 1] += c;
	}

	for (int i = 1; i <= n; i++, puts("")) 
		for (int j = 1; j <= m; j++) {
			f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
			cout << a[i][j] + f[i][j] << " ";
		}

	return 0;
}