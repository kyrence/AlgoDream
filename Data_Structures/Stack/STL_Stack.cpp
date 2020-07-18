#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

stack<int> s;
int t, n;

int main() {
	cin >> t;
	while (t--) {
		string op; int x;
		cin >> op;
		if (op == "push") {
			cin >> x;
			s.push(x);
		} else if (op == "query") cout << s.top() << endl;
		else if (op == "pop") s.pop();
		else puts(s.empty() ? "YES" : "NO");
	}

	return 0;
}