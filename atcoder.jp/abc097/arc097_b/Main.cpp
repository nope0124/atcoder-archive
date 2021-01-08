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
/* Union-Find木 */

struct UnionFind {
    vector<ll> par;
    
    UnionFind(ll n) : par(n, -1) { }
    void init(ll n) { par.assign(n, -1); }
    
    ll root(ll x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
   

    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }
    
    bool merge(ll x, ll y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    ll size(ll x) {
        return -par[root(x)];
    }
};

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll N, M; cin >> N >> M;
  vector<ll> V(N);
  rep (i, N) cin >> V[i], V[i]--;
  UnionFind uf(2 * N);
  rep (i, N) uf.merge(i, V[i] + N);
  rep (i, M) {
    ll a, b; cin >> a >> b; a--; b--;
    uf.merge(a, b);
  }
  vector<map<ll, ll>> mp(100010);
  rep (i, 2 * N) {
    ll id = uf.root(i);
    if (id >= N) id -= N;
    ll tmp = i;
    if (tmp >= N) tmp -= N;
    mp[id][tmp]++;
  }
  ll ans = 0;
  rep (i, 100010) {
    for (auto c: mp[i]) {
      if (c.second > 1) ans++;
    }
  }
  cout << ans << endl;
}