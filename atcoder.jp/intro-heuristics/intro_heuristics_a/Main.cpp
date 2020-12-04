/* Marathon */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pint;
const ll INF = 1e16;
#define rep(i, n) for(ll i = ll(0); i < ll(n); i++)
#define Rep(i, n) for(ll i = ll(1); i < ll(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265358979323846
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

/*bool cmp(pint a, pint b) { return a.second < b.second; }*/

ll d = 365;
vector<ll> c(26), ans(d, 0);
vector<vector<ll>> s(d, vector<ll>(26, 0));


ll simulate() {
  ll sum = 0;
  map<ll, ll> last;
  rep (i, 26) last[i] = 0;
  rep (i, d) {
    sum += s[i][ans[i]];
    last[ans[i]] = i + 1;
    rep (j, 26) {
      sum -= c[j] * (i + 1 - last[j]);
    }
  }
  return sum;
}

ll simulate2(ll ni, ll nj, ll tmp) {
  tmp -= s[ni][ans[ni]];
  tmp += s[ni][nj];
  vector<ll> last(2, 0);
  rep (i, d) {
    if (ans[i] == ans[ni]) {
      last[0] = i + 1;
    }
    if (ans[i] == nj) {
      last[1] = i + 1;
    }
    tmp += c[ans[ni]] * (i + 1 - last[0]);
    tmp += c[nj] * (i + 1 - last[1]);
  }
  last[0] = last[1] = 0;
  ll save = ans[ni];
  ans[ni] = nj;
  rep (i, d) {
    if (ans[i] == save) {
      last[0] = i + 1;
    }
    if (ans[i] == nj) {
      last[1] = i + 1;
    }
    tmp -= c[save] * (i + 1 - last[0]);
    tmp -= c[nj] * (i + 1 - last[1]);
  }
  return tmp;
}
 


void OUTPUT(vector<ll> ans) {
  rep (i, ans.size()) cout << ans[i] + 1 << "\n";
  return;
}

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  cin >> d;
  rep (i, 26) cin >> c[i];
  rep (i, 365) rep (j, 26) cin >> s[i][j];
  map<ll, ll> last;
  rep (i, 26) last[i] = 0;
  ll sum = 0;
  rep (i, d) {
    ll tmp = -INF;
    ll id = 0;
    vector<ll> save(26, 0);
    rep (j, 26) save[j] = last[j];
    rep (j, 26) {
      ll tmp2 = 0;
      tmp2 += s[i][j];
      last[j] = i + 1;
      rep (k, 26) {
        tmp2 -= c[k] * (i + 1 - last[k]);
      }
      if (tmp2 > tmp) {
        tmp = tmp2;
        id = j;
      }
      last[j] = save[j];
    }
    last[id] = i + 1;
    ans[i] = id;
  }
  ll tmp = simulate();
  rep (i, 1250000) {
    ll ni = rand() % 365;
    ll nj = rand() % 26;
    ll save = ans[ni];
    ll tmp2 = simulate2(ni, nj, tmp);
    if (tmp < tmp2) {
      tmp = tmp2;
    } else {
      ans[ni] = save;
    }
  }
  OUTPUT(ans);
}