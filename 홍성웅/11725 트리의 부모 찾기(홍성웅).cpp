#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int> node[100001];
int root[100001];

void Postorder(int vertex, int R) {
	for (int i = 0; i < node[vertex].size(); i++) {
		int nx = node[vertex][i];
		if (nx != R&&nx>0) {
			Postorder(nx, vertex);
		}
	}
	root[vertex] = R;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	Postorder(1, 0);
	for (int i = 2; i <= n; i++) {
		cout << root[i] << '\n';
	}
}