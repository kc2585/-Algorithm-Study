#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, p;
		cin >> p >> d;
		v.push_back(pair<int,int>(d,p));
	}
	sort(v.begin(), v.end(), compare);
	priority_queue<int> pq;
	int idx = 0;
	int ans = 0;
	for (int i = 10000; i >= 1; i--) {
		while (idx < n && i <= v[idx].first) {
			pq.push(v[idx++].second);
		}
		if (pq.size()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << '\n';
}