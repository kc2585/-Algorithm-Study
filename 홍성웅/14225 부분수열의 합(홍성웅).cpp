#include<iostream>
#include<vector>
#include<set>

using namespace std;
int arr[20];
bool chk[2000000];
int n;

void sol(int idx, int sum) {
	if (idx == n) {
		chk[sum] = 1;
		return;
	}
	sol(idx + 1, sum + arr[idx]);
	sol(idx + 1, sum);
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sol(0, 0);
	int idx = 1;
	while (1) {
		if (!chk[idx]) {
			cout << idx << '\n';
			break;
		}
		idx++;
	}
}