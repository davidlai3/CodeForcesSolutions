#include <bits/stdc++.h>    
#define ll long long    
#define pb push_back    
#define mod 1000000007
using namespace std;    
    
    
void sol() {    
	char s[11];
	cin >> s;

	char check = s[0];
	for (int i = 0; i < strlen(s); i++) {
		if (check != s[i]) {
			cout << "YES" << endl;
			char temp = s[i];
			s[i] = s[0];
			s[0] = temp;
			cout << s << endl;
			return;
		}
	}
	cout << "NO" << endl;
		
}    
    
    
int main() {    
  int t = 1;    
  cin >> t;    
  while (t--) {    
    sol();    
  }    
}    
