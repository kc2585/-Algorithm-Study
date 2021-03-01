#include<iostream>

using namespace std;
int n, m;
int graph[501][501];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		graph[s][e] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][k]&& graph[k][j]) {
					graph[i][j] = 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (!graph[i][j] && !graph[j][i]) {
				cnt++;
			}
		}
		if (!cnt) ans++;
	}
	cout << ans << '\n';
}