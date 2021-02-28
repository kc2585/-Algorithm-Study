#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;

int n, m;
vector<int> graph[10001];
bool visited[10001];
int hack[10001];
int cnt;
void dfs(int node) {
	hack[node]++;
	cnt = max(cnt, hack[node]);
	for (int i = 0; i < graph[node].size(); i++) {
		int nx = graph[node][i];
		if (!visited[nx]) {
			visited[nx] = 1;
			dfs(nx);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		dfs(i);
	}
	for (int i = 1; i <= n; i++) {
		if (cnt == hack[i]) cout << i << ' ';
	}
}