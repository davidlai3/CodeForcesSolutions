#include <bits/stdc++.h>    
#define ll long long    
#define pb push_back    
#define MOD 1000000007
using namespace std;    

/*
 * TLDR: Matrix exponentiation on transition matrix to count paths
 */
vector<vector<int>> id(size_t n) {
	vector<vector<int>> result(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		result[i][i] = 1;
	}
	return result;
}
    
vector<vector<int>> mult(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2) {
	size_t n = mat1.size();
	vector<vector<int>> res(n, vector<int>(n, 0)); // result matrix
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			for (size_t k = 0; k < n; k++) {
				res[i][j] += (mat1[i][k] * mat2[k][j]);
				res[i][j] %= MOD;
			}
		}
	}
	return res;
}
    
vector<vector<int>> expo(vector<vector<int>> &mat, int pow) {
	size_t n = mat.size();
	vector<vector<int>> res = id(n);
	if (pow == 0) return res;
	if (pow == 1) return mat;

	for (; pow > 0; pow >>= 1, mat = mult(mat, mat)) {
		if (pow & 1) res = mult(res, mat);
	}

	return res;
}


void sol() {
	int m, n; cin >> m >> n;
	vector<int> s(m), l(m), t(m);
	for (int i = 0; i < m; i++) cin >> s[i];
	for (int i = 0; i < m; i++) cin >> l[i];
	for (int i = 0; i < m; i++) t[i] = s[i] + l[i];

	vector<vector<int>> dp(m, vector<int>(m, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] += (t[i]*t[j]) - (l[i]*l[j]);
		}
	}

	
	dp = expo(dp, n); // matrix exponentiation

	int sum = 0;
	for (int i = 0; i < m; i++) {
		sum += dp[i][0];
		sum %= MOD;
	}
	cout << sum << endl;

}    

    
    
int main() {
	ios_base::sync_with_stdio(false);
  int t = 1;    
  //cin >> t;    
  while (t--) {    
    sol();    
  }    
}    
