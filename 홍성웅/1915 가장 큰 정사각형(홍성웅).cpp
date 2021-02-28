#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[1001][1001];
int dp[1001][1001];
int n, m;
int ans;
void go() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0||arr[i][j]==0) continue;
			arr[i][j] = min({ arr[i][j - 1],arr[i - 1][j],arr[i - 1][j - 1] }) + 1;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, arr[i][j]);
		}
	}
	cout << ans*ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	go();
}