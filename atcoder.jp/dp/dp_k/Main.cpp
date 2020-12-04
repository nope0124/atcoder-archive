#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (ll i = ll(0); i < ll(n); i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    IOS;
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep (i, n) cin >> v[i];
    bool dp[k + 1];
    rep (i, k + 1) dp[i] = false;
    rep (i, k + 1) {
        rep (j, n) {
            if (i - v[j] >= 0) dp[i] |= !dp[i - v[j]];
        }
    }
    if (dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
}