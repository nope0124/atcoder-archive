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
  ll N, K; cin >> N >> K;
  vector<ll> P(N), C(N);
  rep (i, N) cin >> P[i], P[i]--;
  rep (i, N) cin >> C[i];
  vector<vector<ll>> doubling(60, vector<ll>(N));
  vector<vector<ll>> sum(60, vector<ll>(N));
  vector<vector<ll>> summax(60, vector<ll>(N, 0));
  rep (i, N) doubling[0][i] = P[i];
  rep (i, N) sum[0][i] = C[i];
  rep (i, N) summax[0][i] = C[i];
  rep (d, 59) rep (i, N) doubling[d + 1][i] = doubling[d][doubling[d][i]];
  rep (d, 59) rep (i, N) sum[d + 1][i] = sum[d][i] + sum[d][doubling[d][i]];
  rep (d, 59) rep (i, N) summax[d + 1][i] = max(summax[d][i], sum[d][i] + summax[d][doubling[d][i]]);
  ll ans = -INF;
  rep (i, N) {
    ll id = i;
    ll tmp = 0;
    rep (j, 60) {
      if (K & (1LL << j)) {
        chmax(ans, tmp + summax[j][id]);
        tmp += sum[j][id];
        id = doubling[j][id];
      }
    }
    chmax(ans, tmp);
  }
  cout << ans << endl;
}