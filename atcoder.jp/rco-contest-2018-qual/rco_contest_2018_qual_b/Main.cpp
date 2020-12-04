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

struct INFO{ll x, y, id;};

ll H = 200, W = 200, D = 16000, K = 4000;
ll num = 500;

vector<vector<ll> > board(H, vector<ll>(W, -1));
vector<ll> X(D), Y(D);
ll sum;

struct Status {
  ll a, b, c, d;
};

ll getScore() {
  ll ans = 0;
  rep (i, D - 1) {
     ans += abs(X[i] - X[i + 1]) + abs(Y[i] - Y[i + 1]);
  }
  return ans;
}

ll getScore1(ll id, ll nx, ll ny) {
  ll ans = sum;
  if (id - 1 >= 0) ans -= abs(X[id - 1] - X[id]) + abs(Y[id - 1] -Y[id]);
  if (id - 1 >= 0) ans += abs(X[id - 1] - nx) + abs(Y[id - 1] - ny);
  if (id + 1 < D) ans -= abs(X[id + 1] - X[id]) + abs(Y[id + 1] -Y[id]);
  if (id + 1 < D) ans += abs(X[id + 1] - nx) + abs(Y[id + 1] - ny);
  return ans;
}




vector<Status> ans;



ll solve(ll id, ll nx, ll ny) {
  ll tmp2 = getScore1(id, nx, ny);
  return tmp2;
}

INFO simulate(ll t) {
  while(1) {
    ll id = rand() % D;
    ll nx = rand() % W;
    ll ny = rand() % H;
    while(1) {
      nx = rand() % W;
      ny = rand() % H;
      if (board[ny][nx] == -1) break;
    }
    ll tmp2 = solve(id, nx, ny);
    if (sum - tmp2 < 180 - t / 200) continue;
    return INFO{nx, ny, id};
  }
}



void OUTPUT(vector<Status> ans) {
  rep (i, ans.size()) {
    cout << ans[i].a << ' ' << ans[i].b << ' ' << ans[i].c << ' ' << ans[i].d << "\n";
  }
  return;
}

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  cin >> H >> W >> D >> K;
  rep (i, D) {
    cin >> Y[i] >> X[i];
    board[Y[i]][X[i]] = i;
  }
  sum = getScore();
  rep (i, K) {
    INFO p = simulate(i);
    Status st = {Y[p.id], X[p.id], p.y, p.x};
    ans.push_back(st);
    swap(board[Y[p.id]][X[p.id]], board[p.y][p.x]);
    Y[p.id] = p.y;
    X[p.id] = p.x;
  }
  OUTPUT(ans);
}