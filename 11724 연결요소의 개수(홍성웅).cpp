#include<iostream>
#include<vector>
using namespace std;

bool visited[1001];
vector<vector<int>>v;
int n, m, cnt;

void dfs(int idx) {
	visited[idx] = 1;
	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i];
		if (visited[next])continue;
		visited[next] = 1;
		dfs(next);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> n >> m;
	v.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i])continue;
		dfs(i); cnt++;
	}

	cout << cnt << '\n';
}