/* C++ */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
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
vector<ll> compress(vector<ll> &v) {
  ll N = v.size();
  vector<ll> vals;
  if (N == 0) return vals;
  rep (i, N) {
    rep (d, 2) {
      vals.push_back(v[i] + d);
    }
  }
  sort(ALL(vals));
  vals.erase(unique(ALL(vals)), vals.end());
  rep (i, N) v[i] = lower_bound(ALL(vals), v[i]) - vals.begin();
  return vals;
}

ll W, H;

vector<ll> compress2(vector<ll> &v1, vector<ll> &v2) {
  vector<ll> vals;
  ll N = v1.size();
  if (N == 0) return vals;
  rep (i, N) {
    rep (d, 2) {
      vals.push_back(v1[i] + d);
      vals.push_back(v2[i] + d);
    }
  }
  sort(ALL(vals));
  vals.erase(unique(ALL(vals)), vals.end());
  rep (i, N) {
    v1[i] = lower_bound(ALL(vals), v1[i]) - vals.begin();
    v2[i] = lower_bound(ALL(vals), v2[i]) - vals.begin();
  }
  return vals;
}



/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll N; cin >> W >> H >> N;
  vl X1(N), X2(N), Y1(N), Y2(N);
  rep (i, N) cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
  X1.push_back(0);
  Y1.push_back(0);
  X2.push_back(W);
  Y2.push_back(H);
  vl X = compress2(X1, X2);
  vl Y = compress2(Y1, Y2);
  W = X.size(), H = Y.size();
  vector<vector<short>> V(H, vector<short>(W, 0));
  rep (i, N) {
    V[Y1[i]][X1[i]]++;
    V[Y2[i]][X2[i]]++;
    V[Y1[i]][X2[i]]--;
    V[Y2[i]][X1[i]]--;
  }
  rep (i, H) Rep (j, 1, W) V[i][j] += V[i][j - 1];
  Rep (i, 1, H) rep (j, W) V[i][j] += V[i - 1][j];
  H -= 2;
  W -= 2;
  ll ans = 0;
  rep (i, H) {
    rep (j, W) {
      if (V[i][j] > 0) continue;
      queue<pint> que;
      ans++;
      V[i][j] = 1;
      que.push(pint(j, i));
      while (!que.empty()) {
        auto c = que.front(); que.pop();
        rep (i, 4) {
          ll nx = c.first + dx[i];
          ll ny = c.second + dy[i];
          if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
          if (V[ny][nx] > 0) continue;
          V[ny][nx] = 1;
          que.push(pint(nx, ny));
        }
      }
    }
  }
  cout << ans << endl;
}