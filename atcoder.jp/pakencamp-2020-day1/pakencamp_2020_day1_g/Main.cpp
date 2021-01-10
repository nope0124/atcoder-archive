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
/* 累積和 */

vector<ll> acc_sum(vector<ll> v, ll ind = 1, bool rev = false) {
  ll n = v.size();
  if (rev) reverse(ALL(v));
  if (ind == 1) {
    vector<ll> ans(n + 1, 0);
    rep(i, n) ans[i + 1] = ans[i] + v[i];
    if (rev) reverse(ALL(ans));
    return ans;
  } else if (ind == 0) {
    vector<ll> ans(n, 0);
    rep(i, n) {
      if (i == 0) ans[i] = v[i];
      else ans[i] = ans[i - 1] + v[i];
    }
    if (rev) reverse(ALL(ans));
    return ans;
  }
  vector<ll> ans(n, INF);
  return ans;
}

vector<vector<ll>> two_acc_sum(vector<vector<ll>> v) {
  ll h = v.size();
  ll w = v[0].size();
  vector<vector<ll>> ans(h + 1, vector<ll>(w + 1, 0));
  rep(i, h) rep(j, w) ans[i + 1][j + 1] = ans[i][j + 1] + ans[i + 1][j] - ans[i][j] + v[i][j];
  return ans;
}
/* 空の配列でRE */

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll N, M; cin >> N >> M;
  vector<ll> L(M), R(M), X(M);
  rep (i, M) cin >> L[i] >> R[i] >> X[i], L[i]--;
  ll ans = -1;
  rep (bit, (1LL << N)) {
    vector<ll> tmp(N, 0);
    ll cnt = 0;
    rep (i, N) if (bit & (1LL << i)) tmp[i] = 1, cnt++;
    bool flag = true;
    vector<ll> sum = acc_sum(tmp);
    rep (i, M) {
      if (sum[R[i]] - sum[L[i]] != X[i]) flag = false;
    }
    if (flag) chmax(ans, cnt);
  }
  cout << ans << endl;
}