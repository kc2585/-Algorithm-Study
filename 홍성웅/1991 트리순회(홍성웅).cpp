#include<iostream>
#include<string.h>
using namespace std;

int arr[26][2];
void Preorder(int node) {
	cout << char(node +'A');
	if (arr[node][0]!=-1) {
		Preorder(arr[node][0]);
	}
	if (arr[node][1]!=-1) {
		Preorder(arr[node][1]);
	}
}
void Inorder(int node) {
	if (arr[node][0] != -1) {
		Inorder(arr[node][0]);
	}
	cout << char(node + 'A');
	if (arr[node][1] != -1) {
		Inorder(arr[node][1]);
	}
}
void Postorder(int node) {
	if (arr[node][0] != -1) {
		Postorder(arr[node][0]);
	}
	if (arr[node][1] != -1) {
		Postorder(arr[node][1]);
	}
	cout << char(node + 'A');
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(arr, -1, sizeof(arr)); 

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		if (left != '.') arr[root - 'A'][0] = left - 'A';
		if( right !='.') arr[root - 'A'][1] = right - 'A';
	}
	Preorder(0); cout << '\n';
	Inorder(0); cout << '\n';
	Postorder(0); cout << '\n';
}