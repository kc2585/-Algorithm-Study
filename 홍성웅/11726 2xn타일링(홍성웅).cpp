#include<iostream>
#include<algorithm>
using namespace std;
int n;
int dp[1001];
void go() {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	go();
	cout << dp[n] << '\n';
}