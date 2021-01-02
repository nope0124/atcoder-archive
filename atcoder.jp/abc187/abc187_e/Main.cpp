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
vector<ll> graph[200010];
vector<ll> cost(200010, 0);

void dfs(ll v, ll p) {
  for (auto c: graph[v]) {
    if (c == p) continue;
    cost[c] += cost[v];
    dfs(c, v);
  }
}

ll parent[50][200010];
ll depth[200010];

void dig(ll n,ll p,ll d){
  parent[0][n]=p;
  depth[n]=d;
  for(auto c:graph[n]) if(c!=p) dig(c,n,d+1);
}

void init(ll n){
  dig(0,-1,0);
  rep(i,49) rep(j,n){
    if(parent[i][j]<0) parent[i+1][j]=-1;
    else parent[i+1][j]=parent[i][parent[i][j]];  
  }
}
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll N; cin >> N;
  vector<ll> A(N - 1), B(N - 1);
  rep (i, N - 1) cin >> A[i] >> B[i], A[i]--, B[i]--;
  rep (i, N - 1) {
    graph[A[i]].push_back(B[i]);
    graph[B[i]].push_back(A[i]);
  }
  ll Q; cin >> Q;
  ll sum = 0;
  init(N);
  rep (i, Q) {
    ll t, e, x; cin >> t >> e >> x; e--;
    if (t == 1) {
      if (depth[A[e]] > depth[B[e]]) cost[A[e]] += x;
      else cost[B[e]] += -x, sum += x;
    } else if (t == 2) {
      if (depth[A[e]] < depth[B[e]]) cost[B[e]] += x;
      else cost[A[e]] += -x, sum += x;
    }    
  }
  dfs (0, -1);
  rep (i, N) cost[i] += sum;
  rep (i, N) cout << cost[i] << endl;
}