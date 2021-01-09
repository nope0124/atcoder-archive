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
  string S; cin >> S;
  ll N = S.size();
  ll X, Y; cin >> X >> Y;
  vector<ll> dx, dy;
  ll start = 0;
  ll tmp = 0;
  bool ok = true;
  ll type = 1;
  rep (i, N) {
    if (S[i] == 'T') {
      if (!ok) {
        if (type == 1) dx.push_back(tmp);
        else dy.push_back(tmp);
      }
      tmp = 0;
      type *= -1;
      ok = false;
    } else {
      tmp++;
      if (ok) start++;
    }
  }
  if (!ok) {
    if (type == 1) dx.push_back(tmp);
    else dy.push_back(tmp);
  }
  ll NX = dx.size();
  ll NY = dy.size();
  vector<vector<bool>> dpx(NX + 1, vector<bool>(16010, false));
  vector<vector<bool>> dpy(NY + 1, vector<bool>(16010, false));
  dpx[0][start + 8005] = true;
  dpy[0][0 + 8005] = true;
  rep (i, NX) {
    rep (j, 16010) {
      if (j + dx[i] < 16010) dpx[i + 1][j + dx[i]] = dpx[i + 1][j + dx[i]] | dpx[i][j];
      if (j - dx[i] >= 0) dpx[i + 1][j - dx[i]] = dpx[i + 1][j - dx[i]] | dpx[i][j];
    }
  }
  rep (i, NY) {
    rep (j, 16010) {
      if (j + dy[i] < 16010) dpy[i + 1][j + dy[i]] = dpy[i + 1][j + dy[i]] | dpy[i][j];
      if (j - dy[i] >= 0) dpy[i + 1][j - dy[i]] = dpy[i + 1][j - dy[i]] | dpy[i][j];
    }
  }
  if (dpx[NX][8005 + X] && dpy[NY][8005 + Y]) cout << "Yes" << endl;
  else cout << "No" << endl;
}