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
  ll X, Y; cin >> X >> Y;
  if (X == 0 && Y == 0) {
    cout << "1 1" << endl;
    return 0;
  } else if (X == 0) {
    cout << 2 * Y << ' ' << Y << endl;
    return 0;
  } else if (Y == 0) {
    cout << X << ' ' << 2 * X << endl;
    return 0;
  }
  if (X < Y) {
    cout << X + Y << ' ' << Y << endl;
  } else if (X > Y) {
    cout << X << ' ' << X + Y << endl;
  } else {
    cout << -1 << endl;
  }
}