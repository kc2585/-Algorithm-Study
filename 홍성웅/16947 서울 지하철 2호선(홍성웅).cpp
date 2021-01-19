#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int n;
vector<int> v[3003];
int chk[3003];
int dist[3003];
int dfs(int cur, int p) {
	if (chk[cur] == 1) {
		return cur;
	}
	chk[cur] = 1;
	for (int i = 0; i < v[cur].size();i++) {
		int nx = v[cur][i];
		if (p == nx) continue;
		int res = dfs(nx, cur);
		if (res == -2) return -2;
		if (res >= 0) {
			chk[cur] = 2;
			return (cur == res) ? -2 : res;
		}
	}
	return -1;
}
void bfs() {
	memset(dist, 0, sizeof(dist));
	queue<int> q;
	for (int i = 1; i <= n ; i++) {
		if (chk[i] == 2) q.push(i);
		else {
			dist[i] = -1;
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nx = v[cur][i];
			if (dist[nx] == -1) {
				q.push(nx);
				dist[nx] = dist[cur] + 1;
			}
		}
	}
	
}
void sol() {
	dfs(1, -1);
	bfs();
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << ' ';
	}
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}
	sol();
}