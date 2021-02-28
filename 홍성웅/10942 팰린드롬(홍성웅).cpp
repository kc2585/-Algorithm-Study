#include<iostream>
#include<string.h>
using namespace std;

int n, m;
int arr[2020];
int dp[2020][2020];
bool isPalendrom(int s, int e) {
	if (s >= e) {
		return 1;
	}
	int& ret = dp[s][e];
	if (ret!=-1) {
		return ret;
	}
	if (arr[s] == arr[e]) {
		return ret = isPalendrom(s + 1, e - 1);
	}
	else return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << isPalendrom(s, e)<<'\n';
	}
}