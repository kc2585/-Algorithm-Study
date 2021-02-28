#include<iostream>
#include<algorithm>
#define MOD 1000000009
using namespace std;
typedef long long ll;
int n, t;
ll dp[1000001];
void go() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 1000001; i++) {
		dp[i] = (dp[i - 3] % MOD) + (dp[i - 2] % MOD) + (dp[i - 1] % MOD);
		dp[i] %= MOD;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	go();
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}