#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int arr[21][21];
bool team[21];
int sum_s,sum_l;
int res = 1e9;
void dfs(int idx, int cnt) {
	if (cnt == n / 2) {
		vector<int> start;
		vector<int> link;
		for (int i = 0; i < n; i++) {
			if (team[i]==1) start.push_back(i);
			else link.push_back(i);
		}
		int sum_s=0, sum_l=0;
		for (int i=0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				sum_s += arr[start[i]][start[j]];
				sum_l += arr[link[i]][link[j]];
			}
		}
		res = min(res, abs(sum_s - sum_l));
		return;
	}
	for (int i = idx; i < n; i++) {
		if(team[i])continue;
		team[i] = 1;
		dfs(i, cnt + 1);
		team[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0);
	cout << res << '\n';
}