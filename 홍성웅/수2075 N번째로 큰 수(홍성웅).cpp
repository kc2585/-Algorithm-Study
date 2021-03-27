#include<iostream>
#include<queue>
using namespace std;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 0; i < n ; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			pq.push(num);
		}
		for (int k = 0; k < n; k++) {
			pq.pop();
		}
	}
	cout << pq.top() << '\n';
}