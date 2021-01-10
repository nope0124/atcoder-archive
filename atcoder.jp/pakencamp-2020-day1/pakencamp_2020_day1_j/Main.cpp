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
/* 素数判定、素因数分解、約数列挙 */

const ll MAX_N=10001000;
vector<bool> sieve_of_eratosthenes() {
  vector<bool> isPrime(MAX_N + 1, true);
  /* isPrime[1] = false; */
  for (ll i = 2; i <= MAX_N; i++) {
    if (isPrime[i]) {
      for (ll j = 2 * i; j <= MAX_N; j += i) {
        isPrime[j] = false;
      }
    }
  }
  return isPrime;
}

vector<pint> prime_factorize(ll n) {
  vector<pint> ans;
  for (ll p = 2; p <= sqrt(n); p++) {
    if (n % p != 0) continue;
    ll cnt = 0;
    while (n % p == 0) {
      n /= p;
      cnt++;
    }
    ans.push_back(pint(p, cnt));
  }
  if (n != 1) ans.push_back(pint(n, 1));
  return ans;
}

vector<ll> divisor(ll n) {
  // O(√n)
  vector<ll> ans;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ans.push_back(i);
      if (i * i != n) ans.push_back(n / i);
    }
  }
  sort(ALL(ans));
  return ans;
}

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll N; cin >> N;
  vector<bool> isPrime = sieve_of_eratosthenes();
  ll ans = 0;
  Rep (i, 11, 10001000) {
    if (isPrime[i]) {
      ans++;
      cout << i << ' ' << (i * i - 1) / 2 << ' ' << (i * i + 1) / 2 << '\n';
    }
    if (ans == 100000) return 0;
  }
}