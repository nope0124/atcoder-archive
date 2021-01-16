/* C++ */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
typedef pair<ll, ll> pint;
const ll MOD = 998244353;
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

/* コンビネーション */

const ll MAX = 10;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (ll i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  COMinit();
  ll H, W, K; cin >> H >> W >> K;
  vector<vector<char>> board(H, vector<char>(W, '.'));
  rep (i, K) {
    ll h, w; char type; cin >> h >> w >> type; h--; w--;
    board[h][w] = type;
  }
  vector<vector<ll>> dp(H + 1, vector<ll>(W + 1, 0));
  dp[0][0] = POW(3, H * W - K, MOD);
  rep (i, H) {
    rep (j, W) {
      if (board[i][j] == 'X') {
        dp[i + 1][j] += dp[i][j];
        dp[i + 1][j] %= MOD;
        dp[i][j + 1] += dp[i][j];
        dp[i][j + 1] %= MOD;
      } else if (board[i][j] == 'R') {
        dp[i][j + 1] += dp[i][j];
        dp[i][j + 1] %= MOD;
      } else if (board[i][j] == 'D') {
        dp[i + 1][j] += dp[i][j];
        dp[i + 1][j] %= MOD;
      } else {
        dp[i + 1][j] += dp[i][j] * 2 * inv[3];
        dp[i + 1][j] %= MOD;
        dp[i][j + 1] += dp[i][j] * 2 * inv[3];
        dp[i][j + 1] %= MOD;
      }
    }
  }
  cout << dp[H - 1][W - 1] << endl;
}