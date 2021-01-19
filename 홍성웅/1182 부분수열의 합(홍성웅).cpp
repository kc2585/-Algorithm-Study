#include<iostream>

using namespace std;
int n,k,res;
int arr[22];
void dfs(int idx, int sum) {
	if (idx == n) {
		if ( sum == k) {
			res++;
		}
		return;
	}
	dfs(idx + 1, sum + arr[idx]);
	dfs(idx + 1, sum);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> n>>k;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	dfs(0, 0);
	if (k == 0) res--;
	cout << res << '\n';
}