#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<pair<int, int>> v;
int cnt;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back({ end,start });
	}
	sort(v.begin(), v.end());
	int idx = 0;
	for (int i = 0; i < v.size(); i++) {
		if (idx <= v[i].second) {
			idx = v[i].first;
			cnt++;
		}
	}
	cout << cnt << '\n';
}