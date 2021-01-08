/* C++ */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pint;
const ll MOD = 1000000007;
const ll INF = 922337203685477580;
#define rep(i, n) for(ll i = (ll)0; i < (ll)(n); i++)
#define Rep(i, s, t) for(ll i = (ll)(s); i < (ll)(t); i++)
#define ALL(a)  (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265358979323846
#define ifYN(x) cout << (x ? "Yes" : "No") << "\n"
ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0, 0, -1, 1};

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

ll Len(ll n) {
  if (n == 0) return 1;
  ll s = 0;
  while (n != 0) s++, n /= 10;
  return s;
}

ll Sint(ll n) {
  ll ans = 0;
  while (n != 0) ans += n % 10, n /= 10;
  return ans;
}

ll Svec(vector<ll> v){
  ll n = 0;
  rep(i, (ll)v.size()) n += v[i];
  return n;
}

ll GCD(ll a, ll b) {
  return b ? GCD(b, a % b) : a;
}

ll LCM(ll a, ll b){
  return a / GCD(a, b) * b;
}

ll POW(ll a, ll n, ll mod = INF) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

void dis(vector<ll> v){ rep(i, v.size()) cout << v[i] << endl; }

void dis2(vector<vector<ll> > v) {
  rep (i, v.size()) {
    rep (j, v[0].size()) cout << v[i][j] << ' ';
    cout << endl;
  }
}

bool cmp(pint a, pint b) { return a.second < b.second; }

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  vector<ll> V(2);
  ll A, B, E, F; cin >> A >> B >> V[0] >> V[1] >> E >> F;
  vector<vector<bool>> dp(3, vector<bool>(3001, false));
  dp[0][0] = true;
  rep (i, 2) {
    rep (j, 3001) {
      dp[i + 1][j] = dp[i + 1][j] | dp[i][j];
      if (j - V[i] >= 0) dp[i + 1][j] = dp[i + 1][j] | dp[i + 1][j - V[i]];
    }
  }
  ll C = 0, D = 100;
  ll L = min(A, B) * 100, R = 0;
  vector<ll> S;
  rep (i, 3001) if (dp[2][i]) S.push_back(i);
  rep (i, 30 / A + 1) {
    rep (j, 30 / B + 1) {
      if (i == 0 && j == 0) continue;
      if (A * i * 100 + B * j * 100 > F) continue;
      ll tmp = min(F - A * i * 100 - B * j * 100, E * (A * i + B * j));
      ll ans = S[upper_bound(ALL(S), tmp) - S.begin() - 1];
      if ((A * i + B * j + ans) * C < ans * D) {
        C = ans;
        D = (A * i + B * j + ans);
        L = A * i * 100 + B * j * 100 + ans;
        R = ans;
      }
    }
  }
  cout << L << ' ' << R << endl;
}