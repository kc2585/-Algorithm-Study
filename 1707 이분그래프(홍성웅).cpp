#include<iostream>
#include<vector>
using namespace std;

int Color[20001];
vector<int>v[20001];

void dfs(int idx,int color) {
	Color[idx] = color;
	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i];
		if (Color[next])continue;
		dfs(next, 3 - color);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int V, E;
		cin >> V >> E;
		for (int i = 1; i <= V; i++) {
			v[i].clear();
			Color[i] = 0;
		}
		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b); v[b].push_back(a);
		}
		for (int i = 1; i <= V; i++) {
			if (Color[i])continue;
			dfs(i, 1);
		}
		int flag = 0;
		for (int i = 1; i <= V; i++) {
			if (flag) break;
			for (int j = 0; j < v[i].size(); j++) {
				if (Color[i] == Color[v[i][j]]) {
					flag = 1;
				}
			}
		}
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}
}