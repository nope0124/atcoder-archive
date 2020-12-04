#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1000000007;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main() {
    IOS;
	ll n;
	cin>>n;
	ll f[110]={};
	rep(i,n) {
		rep(j,10) {
			ll a;
			cin >> a;
			f[i] += a << (9 - j);
		}
	}
	ll p[n][11];
	rep(i,n) {
		rep (j,11) {
			cin >> p[i][j];
		}
	}
	int ans = -1e9;
	for (int i = 1;i < 1024;i++) {
		int cost = 0;
		for (int j = 0;j < n;j++) {
			cost += p[j][__builtin_popcount(f[j] & i)];
		}
		ans = max(ans, cost);
	}
	cout << ans << endl;
}