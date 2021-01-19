#include<iostream>
#include<vector>
#include<string.h>

using namespace std;
int n;
vector<pair<int, int>>v[10001];
bool visited[10001];
int len=0, root=1;
void dfs(int node, int cost) {
	visited[node] = 1;
	if (len < cost) {
		len = cost;
		root = node;
	}
	for (int i = 0; i < v[node].size(); i++) {
		int nx = v[node][i].first;
		int dist = v[node][i].second;
		if (!visited[nx]) {
			dfs(nx, dist + cost);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	memset(visited, 0, sizeof(visited));
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	len = 0;
	dfs(root, 0);
	cout << len << '\n';
}