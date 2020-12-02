#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int n;
int root;
int len;
bool visited[100001];
vector<pair<int, int>> v[100001];

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
			dfs(nx, dist+cost);
		}
	}
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int node;
		cin >> node;
		while (1) {
			int idx, dist;
			cin >> idx;
			if (idx == -1) break;
			cin >> dist;
			v[node].push_back({ idx,dist });
		}
	}
	memset(visited, 0, sizeof(visited));
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	len = 0;
	dfs(root, 0);
	cout << len << '\n';
}