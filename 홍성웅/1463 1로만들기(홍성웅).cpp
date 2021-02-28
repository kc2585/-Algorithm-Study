#include<iostream>
#include<algorithm>
using namespace std;
int n;
int dp[1000001];
void go() {
	dp[0] = 1e9;
	dp[1] = 0;
	for (int i = 2; i <= 1000000; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0&&dp[i]>dp[i/2]+1) {
			dp[i] = dp[i / 2] + 1;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	go();
	cout << dp[n] << '\n';
}