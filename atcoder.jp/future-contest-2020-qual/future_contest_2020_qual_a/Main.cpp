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

struct ANSWER{ll y, x; char r; };
/*bool cmp(pint a, pint b) { return a.second < b.second; }*/

ll n = 40, m = 100, b = 300, gy, gx;
vector<ll> ry(m), rx(m), by(b), bx(b);
vector<char> c(m);
vector<vector<bool>> isBlock(n, vector<bool>(n, false));
vector<vector<ll>> dist(n, vector<ll>(n, INF));
vector<ANSWER> ans;
vector<ANSWER> nans;
ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0, 0, -1, 1};
char type[4] = {'L', 'R', 'U', 'D'};
vector<string> board(n, "........................................");

ll MINT(ll i, ll d) {
  return (i + n + d) % n;
}

bool simulate() {
  ll ans = 0;
  rep (i, m) {
    char dir = c[i];
    ll x = rx[i];
    ll y = ry[i];
    ll cnt = 0;
    while (1) {
      if (board[y][x] != '.') dir = board[y][x]; 
      if (dir == 'U') y = MINT(y, -1);
      if (dir == 'D') y = MINT(y, 1);
      if (dir == 'L') x = MINT(x, -1);
      if (dir == 'R') x = MINT(x, 1);
      if (dir == 'G') {
        ans++;
        break;
      }
      if (cnt >= 1600) break;
      cnt++;
      if (board[y][x] == '#') return false;
    }
  }
  if (ans == m) return true;
  else return false;
}

void OUTPUT(vector<ANSWER> ans) {
  cout << ans.size() << endl;
  rep (i, ans.size()) cout << ans[i].y << ' ' << ans[i].x << ' ' << ans[i].r << '\n';
  return;
}

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  cin >> n >> m >> b >> gy >> gx;
  rep (i, m) cin >> ry[i] >> rx[i] >> c[i];
  rep (i, b) {
    cin >> by[i] >> bx[i];
    isBlock[by[i]][bx[i]] = true;
    board[by[i]][bx[i]] = '#';
  }
  board[gy][gx] = 'G';
  dist[gy][gx] = 0;
  queue<pint> que;
  que.push(pint(gx, gy));
  while(!que.empty()) {
    auto c = que.front();que.pop();
    ll x = c.first;
    ll y = c.second;
    rep (i, 4) {
      ll nx = MINT(x, dx[i]);
      ll ny = MINT(y, dy[i]);
      if (isBlock[ny][nx]) continue;
      if (dist[ny][nx] != INF) continue;
      dist[ny][nx] = dist[y][x] + 1;
      que.push(pint(nx, ny));
    }
  }
  rep (i, n) {
    rep (j, n) {
      if (isBlock[i][j]) continue;
      rep (k, 4) {
        ll nx = MINT(j, dx[k]);
        ll ny = MINT(i, dy[k]);
        if (dist[ny][nx] < dist[i][j]) {
          ans.push_back(ANSWER{i, j, type[k]});
          break;
        }
      }
    }
  }
  
  rep (i, ans.size()) {
    board[ans[i].y][ans[i].x] = ans[i].r;
  }
  
  rep(i, n) {
    rep (j, n) {
      if (board[i][j] == '#' || board[i][j] == 'G') continue;
      char save = board[i][j];
      board[i][j] = '.';
      if (!simulate()) board[i][j] = save;
    }
  }
  
  rep (i, n)  rep (j, n) if (board[i][j] != 'G' && board[i][j] != '.' && board[i][j] != '#') nans.push_back(ANSWER{i, j, board[i][j]});
  OUTPUT(nans);
}