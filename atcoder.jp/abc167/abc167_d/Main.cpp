/* C++ */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pint;
const ll MOD = 1000000007;
const ll INF = 9223372036854775807;
#define rep(i, n) for(ll i = (ll)0; i < (ll)(n); i++)
#define Rep(i, s, t) for(ll i = (ll)(s); i < (ll)(t); i++)
#define ALL(a)  (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265358979323846
#define ifYN(x) cout << (x ? "Yes" : "No") << "\n" 

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

void dis(vector<ll> v){ rep(i, (ll)v.size()) cout << v[i] << endl; }

void dis2(vector<vector<ll>> v) {
  rep (i, (ll)v.size()) {
    rep (j, (ll)v[0].size()) cout << v[i][j] << ' ';
    cout << endl;
  }
}

bool cmp(pint a, pint b) { return a.second < b.second; }

/* Loopを求める */

ll get_loopstart(vector<ll> v, ll start) {
  ll n = v.size();
  vector<bool> reached(n, false);
  while (1) {
    if (reached[start]) break;
    reached[start] = true;
    start = v[start];
  }
  return start;
}


vector<ll> get_preloop(vector<ll> v, ll start, ll loopstart) {
  vector<ll> preloop;
  while (1) {
    if (start == loopstart) break;
    preloop.push_back(start);
    start = v[start];
  }
  return preloop;
}


vector<ll> get_loop(vector<ll> v, ll loopstart) {
  vector<ll> loop;
  ll start = loopstart;
  loop.push_back(loopstart);
  while (1) {
    if (v[loopstart] == start) break;
    loop.push_back(v[loopstart]);
    loopstart = v[loopstart];
  }
  return loop;
}

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll n, k; cin >> n >> k;
  vector<ll> v(n);
  rep (i, n) cin >> v[i], v[i]--;
  ll loopstart = get_loopstart(v, 0);
  vector<ll> preloop = get_preloop(v, 0, loopstart);
  vector<ll> loop = get_loop(v, loopstart);
  if (preloop.size() > k) {
    cout << preloop[k] + 1 << endl;
    return 0;
  }
  k -= preloop.size();
  cout << loop[k % loop.size()] + 1 << endl;
}