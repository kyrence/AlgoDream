#include <bits/stdc++.h>

using namespace std;

deque<int> q;
int t;

int main() {
	cin >> t;
	while (t--) {
		string op; int x;
		cin >> op;
		if (op == "empty") puts(q.empty() ? "YES" : "NO");
		else if (op == "front") cout << q.front() << endl;
		else if (op == "back") cout << q.back() << endl;
		else if (op == "pop_front") q.pop_front();
		else if (op == "pop_back") q.pop_back();
		else if (op == "push_front") {
			cin >> x;
			q.push_front(x);
		} else {
			cin >> x;
			q.push_back(x);
		}
	}

	return 0;
}