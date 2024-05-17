#include <bits/stdc++.h>    
#define ll long long    
#define pb push_back    
#define mod 1000000007
using namespace std;    
    
    
void sol() {
	int n; cin >> n;
	ll int sum = (n * (n+1))*(2*(2*n+1) - 3)/6;
	cout << sum << " " << 2*n << endl;

	for (int i = 0; i < n; i++) {
		cout << 2 << " " << n-i << " ";
		for (int j = 1; j <= n; j++) {
			cout << j;
			if (j != n) cout << " ";
		}
		cout << endl;
		cout << 1 << " " << n-i << " ";
		for (int j = 1; j <= n; j++) {
			cout << j;
			if (j != n) cout << " ";
		}
		cout << endl;
	}
}    
    
    
int main() {    
  int t = 1;    
  cin >> t;    
  while (t--) {    
    sol();    
  }    
}    

