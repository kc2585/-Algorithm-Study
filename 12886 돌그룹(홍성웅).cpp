#include<iostream>
#include<queue>
#include<set>
using namespace std;
typedef struct {
	int a, b, c;
}node;
set<pair<pair<int, int>, int>> s;
bool flag;
queue<node> q;
void bfs() {
	while (q.size()) {
		if (flag) return;
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		if (a == b && b == c) {
			flag = 1;
			return;
		}
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				if (a > b) {
					if (s.find({ {a - b,b + b},c }) == s.end()) {
						q.push({ a - b,b + b,c });
						s.insert({ {a - b,b + b},c });
					}
				}
				if (a < b) {
					if (s.find({ {a+a,b-a},c }) == s.end()) {
						q.push({ a +a,b -a,c });
						s.insert({ {a +a,b -a},c });
					}
				}
			}
			if (i == 1) {
				if (c > b) {
					if (s.find({ {a,b + b},c - b }) == s.end()) {
						q.push({ a ,b + b,c-b });
						s.insert({ {a,b + b},c-b });
					}
				}
				if (c < b) {
					if (s.find({ {a,b - c},c+c }) == s.end()) {
						q.push({ a,b - c,c+c });
						s.insert({ {a,b - c},c+c });
					}
				}
			}
			if (i == 2) {
				if (c > a) {
					if (s.find({ {a+a,b },c - a }) == s.end()) {
						q.push({ a+a ,b,c - a });
						s.insert({ {a+a,b },c - a });
					}
				}
				if (c < a) {
					if (s.find({ {a - c,b} ,c + c }) == s.end()) {
						q.push({ a-c,b,c + c });
						s.insert({ {a-c,b },c + c });
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int A, B, C;
	cin >> A >> B >> C;
	q.push({ A,B,C });
	s.insert({ {A,B},C });
	if ((A + B + C) % 3 != 0) {
		cout << 0 << '\n';
		return 0;
	}
	bfs();
	if (flag) {
		cout << 1 << '\n';
	}
	else cout << 0 << '\n';
}