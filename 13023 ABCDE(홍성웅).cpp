#include<iostream>
#include<vector>

using namespace std;

int n, m;
bool visited[2001];
vector<vector<int>> v;
bool chk;

void dfs(int idx, int cnt) {
	if (chk) return;
	if (cnt == 4) {
		chk = 1;
		return;
	}
	for (int i = 0; i < v[idx].size(); i++) {
		if (visited[v[idx][i]])continue;
		visited[v[idx][i]] = 1;
		dfs(v[idx][i], cnt + 1);
		visited[v[idx][i]] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >>  n >> m;
	v.resize(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		visited[i] = 1;
		dfs(i, 0);
		visited[i] = 0;
	}

	if (chk) cout << 1 << '\n';
	else cout << 0 << '\n';
}