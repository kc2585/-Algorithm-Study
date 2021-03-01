#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int n;
vector<pair<int, int>> p;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int idx, s, e;
		cin >> idx >> s >> e;
		p.push_back({ s,e });
	}
	sort(p.begin(),p.end());
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (pq.size()) {
			if (pq.top().first > p[i].first) {
				cnt++;
			}
			else {
				pq.pop();
			}
		}
		else {
			cnt++;
		}
		int start_time = p[i].first;
		int end_time = p[i].second;
		pq.push({ end_time,start_time });
	}
	cout << cnt << '\n';
}