#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, v;
vector<vector<int>> vt;
bool visited[1001];
void dfs(int idx) {
	visited[idx] = 1;
	cout << idx << ' ';
	for (int i = 0; i< vt[idx].size(); i++) {
		int next = vt[idx][i];
		if (visited[next]) continue;
		dfs(next);
	}
}

void bfs(int idx) {
	queue<int>q;
	visited[idx] = 1;
	q.push(idx);
	while (q.size()) {
		int val = q.front();
		cout << val << ' ';
		q.pop();
		for (int i = 0; i < vt[val].size(); i++) {
			int next = vt[val][i];
			if (visited[next]) continue;
			visited[next] = 1;
			q.push(next);
		}

	}
}

void sol() {
	for (int i = 1; i <= n; i++) {
		sort(vt[i].begin(), vt[i].end());
	}
	memset(visited, 0, sizeof(visited));
	dfs(v);
	cout << '\n';
	memset(visited, 0, sizeof(visited));
	bfs(v);
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> v;
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	sol();
}