#include<iostream>
#include<queue>
#include<set>
#include<string>
using namespace std;
typedef long long ll;
bool flag;
char dir[4] = { '*','+','-','/' };
ll start, goal;
set<ll> s;
ll calc(ll num, int idx) {
	if (idx == 0) {
		return num * num;
	}
	else if (idx == 1) {
		return num + num;
	}
	else if (idx == 2) {
		return num - num;
	}
	else if (idx == 3) {
		return num / num;
	}
}
void bfs() {
	queue<pair<ll, string>>q;
	q.push({ start,"" });
	s.insert(start);
	while (q.size()) {
		int num = q.front().first;
		string st = q.front().second;
		q.pop();
		if (num == goal) {
			cout << st << "\n";
			return;
		}
		for (int i = 0; i < 4; i++) {
			ll tmp = calc(num, i);
			string s_tmp = st + dir[i];
			if (tmp < 1||tmp>1e9) continue;
			if (s.find(tmp) != s.end()) continue;
			s.insert(tmp);
			q.push({ tmp,s_tmp });
		}
	}
	cout << -1 << '\n';
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> start >> goal;
	if (start == goal) {
		cout << 0 << '\n';
		return 0;
	}
	bfs();
}