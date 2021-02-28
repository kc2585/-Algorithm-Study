#include<iostream>
#include<vector>
#include<string>
using namespace std;

int L;
string S;
vector<int> getPartialMatch(const string& N) {
	int M = N.size();
	vector<int> pi(M, 0);

	int begin = 1, matched = 0;
	
	while (begin + matched < M) {
		if (N[begin + matched] == N[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) {
				begin++;
			}
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> L >> S;
	vector<int> pi = getPartialMatch(S);
	cout << L - pi[L - 1]<<'\n';
}