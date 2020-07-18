#include <bits/stdc++.h>

using namespace std;

queue<int> q;
int t;

int main() {
	cin >> t;
	while (t--) {
		string op; int x;
		cin >> op;
		if (op == "push") {
			cin >> x;
			q.push(x);
		} else if (op == "empty") puts(q.empty() ? "YES" : "NO");
		else if (op == "query") cout << q.front() << endl;
		else q.pop();
	}

	return 0;
}