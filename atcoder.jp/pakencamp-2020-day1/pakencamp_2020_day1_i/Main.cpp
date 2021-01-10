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
struct tri{ll x, y, cnt;};
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll H, W; cin >> H >> W;
  ll sx, sy, gx, gy; cin >> sy >> sx >> gy >> gx;
  sx--; gx--;
  sy--; gy--;
  vector<string> V(H);
  rep (i, H) cin >> V[i];
  vector<vector<ll>> dist(H, vector<ll>(W, INF));
  queue<tri> que;
  que.push(tri{sx, sy, 0});
  dist[sy][sx] = 0;
  ll ans = INF;
  while (!que.empty()) {
    auto c = que.front(); que.pop();
    if (c.cnt % 2 == 0) {
      rep (i, 2) {
        ll nx = c.x + dx[i];
        ll ny = c.y + dy[i];
        if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
        if (V[ny][nx] == '#') continue;
        if (dist[ny][nx] != INF) continue;
        dist[ny][nx] = dist[c.y][c.x] + 1;
        que.push(tri{nx, ny, c.cnt + 1});
      }
    } else {
      rep (i, 2) {
        ll nx = c.x + dx[i + 2];
        ll ny = c.y + dy[i + 2];
        if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
        if (V[ny][nx] == '#') continue;
        if (dist[ny][nx] != INF) continue;
        dist[ny][nx] = dist[c.y][c.x] + 1;
        que.push(tri{nx, ny, c.cnt + 1});
      }
    }
  }
  chmin(ans, dist[gy][gx]);
  rep (i, H) rep (j, W) dist[i][j] = INF;
  que.push(tri{sx, sy, 1});
  dist[sy][sx] = 0;
  while (!que.empty()) {
    auto c = que.front(); que.pop();
    if (c.cnt % 2 == 0) {
      rep (i, 2) {
        ll nx = c.x + dx[i];
        ll ny = c.y + dy[i];
        if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
        if (V[ny][nx] == '#') continue;
        if (dist[ny][nx] != INF) continue;
        dist[ny][nx] = dist[c.y][c.x] + 1;
        que.push(tri{nx, ny, c.cnt + 1});
      }
    } else {
      rep (i, 2) {
        ll nx = c.x + dx[i + 2];
        ll ny = c.y + dy[i + 2];
        if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
        if (V[ny][nx] == '#') continue;
        if (dist[ny][nx] != INF) continue;
        dist[ny][nx] = dist[c.y][c.x] + 1;
        que.push(tri{nx, ny, c.cnt + 1});
      }
    }
  }
  chmin(ans, dist[gy][gx]);
  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
}