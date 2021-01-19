#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
#include<queue>
using namespace std;
int ans;
bool chk[10000];
string input[4] = { "D","S","L","R" };
queue<pair<int,string>>q;
void bfs(int A, int B) {
	queue<pair<int, string>>q;
	memset(chk, 0, sizeof(chk));
	q.push({ A,"" });
	chk[A] = 1;
	
	while (q.size()) {
		int num = q.front().first;
		string s = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int val = num;
			if (input[i] == "D") {
				val *= 2;
				val %= 10000;
			}
			else if (input[i] == "S") {
				if (val == 0) val = 9999;
				else val--;
			}
			else if (input[i] == "L") {
				int tmp = val / 1000;
				val %= 1000;
				val *= 10;
				val += tmp;
			}
			else if (input[i] == "R") {
				int tmp = val % 10;
				val /= 10;
				val += tmp * 1000;
			}
			if (!chk[val]) {
				string tmp = s;
				tmp.push_back(input[i][0]);
				if (val == B) {
					cout << tmp << '\n';
					return;
				}
				q.push({ val,tmp });
				chk[val] = 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int A, B;
		cin >> A >> B;
		bfs(A,B);
	}

}