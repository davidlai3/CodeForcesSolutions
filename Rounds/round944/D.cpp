#include <bits/stdc++.h>    
#define ll long long    
#define pb push_back    
#define mod 1000000007
using namespace std;    
    
    
// Why does this pass :sob:
void sol() {    
	string s; cin >> s;
	int count = 1;
	int zo = -1;
	
	int len = s.size();
	for (int i = 0; i < len-1; i++) {
		string window = s.substr(i, 2);
		if (window == "01") zo++;
		if (window == "10") count++;
	}
	int res = zo == -1 ? count : count + zo;
	cout << res << endl;
}    
    
    
int main() {    
  int t = 1;    
  cin >> t;    
  while (t--) {    
    sol();    
  }    
}    
