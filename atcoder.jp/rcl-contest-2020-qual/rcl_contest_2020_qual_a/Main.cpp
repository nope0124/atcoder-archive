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

ll MAX(vector<ll> v) {
  ll ans = 0;
  rep (i, v.size()) {
    chmax(ans, v[i]);
  }
  return ans;
}

/*bool cmp(pint a, pint b) { return a.second < b.second; }*/
ll n =1000, w = 8, k = 6, v = 8, h = 130;
vector<vector<ll>> board(h, vector<ll>(w, -1));
vector<ll> color(n), value(n), ans(n);

void OUTPUT(vector<ll> ans) {
  rep (i, ans.size()) {
    cout << ans[i] << endl;
  }
}

ll scoring() {
  ll sum = 0;
  rep (i, h) {
    bool flag = true;
    vector<ll> tmpColor(k, 0);
    rep (j, w) {
      if (board[i][j] == -1) {
        flag = false;
        break;
      }
      tmpColor[color[board[i][j]]] += value[board[i][j]];
    }
    if (flag) sum += MAX(tmpColor);
  }
  return sum;
}

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  cin >> n >> w >> k >> v;
  rep (i, n) cin >> color[i] >> value[i];
  ll ni = 0;
  rep (i, n) {
    ans[i] = i % 8;
    board[i / 8][i % 8] = i;
  }
  OUTPUT(ans);
}