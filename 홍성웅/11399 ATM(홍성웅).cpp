#include<iostream>
#include<algorithm>

using namespace std;
int n;
int arr[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int time = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += time + arr[i];
		time += arr[i];
	}
	cout << cnt << '\n';
}