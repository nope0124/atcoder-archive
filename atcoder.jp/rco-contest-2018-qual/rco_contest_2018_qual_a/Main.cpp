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
string dir = "LRUD";

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



ll n = 100, K = 8, h = 50, w = 50, t = 2500;
ll Beam = 10;
map<char, ll> mp;
vector<vector<string>> board(n, vector<string>(h));
vector<ll> sx(n), sy(n);
vector<ll> selected(K);
string ans;

bool cmp(pair<ll, string> lhs, pair<ll, string> rhs) {
  return lhs.first > rhs.first;
}

ll Eval(string s) {
  ll ans = 0;
  rep (i, K) {
    ll x = sx[selected[i]];
    ll y = sy[selected[i]];
    bool flag = true;
    vector<vector<bool>> reached(h, vector<bool>(w, false));
    rep (j, s.size()) {
      if (!flag) break;
      if (s[j] == 'U') {
        if (board[selected[i]][y - 1][x] != '#') {
          y--;
        } else {
          ans -= 2;
        }
      }
      if (s[j] == 'D') {
        if (board[selected[i]][y + 1][x] != '#') {
          y++;
        } else {
          ans -= 2;
        }
      }
      if (s[j] == 'L') {
        if (board[selected[i]][y][x - 1] != '#') {
          x--;
        } else {
          ans -= 2;
        }
      }
      if (s[j] == 'R') {
        if (board[selected[i]][y][x + 1] != '#') {
          x++;
        } else {
          ans -= 2;
        }
      }
      if (!reached[y][x] && board[selected[i]][y][x] == 'o') ans+=3;
      else if (board[selected[i]][y][x] =='x') ans -= (t - s.size()) / 2, flag = false;
      reached[y][x] = true;
    }
  }
  return ans;
}
ll aaa = 1350;

void beamSearch() {
  deque<pair<ll, string>> beam;
  deque<pair<ll, string>> nexts;
  string state;
  rep (i, 4) {
    beam.push_back(pair<ll, string>(Eval(state), state));
  }
  while(!beam.empty()) {
    ll cnt = beam.size();
    rep (i, cnt) {
      pair<ll, string> newState = beam.front();
      beam.pop_front();
      if (newState.second.size() == aaa) {
        ans = newState.second;
        return;
      }
      rep (j, 4) {
        if (newState.second.size() >= 1 && mp[newState.second[newState.second.size() - 1]] == j) continue;
        nexts.push_back(pair<ll, string>(Eval(newState.second), newState.second + dir[j]));
      }
    }
    sort(ALL(nexts), cmp);
    for(ll i = 0; i < Beam && !nexts.empty(); i++) {
      beam.push_back(nexts.front());

      nexts.pop_front();
    }
    nexts.clear();
  }
}
void OUTPUT() {
  rep (i, K) {
    if (i == 0) cout << selected[i];
    else cout << ' ' << selected[i];
  }
  cout << endl;
  cout << ans << endl;
}


/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  cin >> n >> K >> h >> w >> t;
  mp['L'] = 1;
  mp['R'] = 0;
  mp['U'] = 3;
  mp['D'] = 2;
  vector<pint> p;
  rep (i, n) {
    rep (j, h) cin >> board[i][j];
  }
  rep (i, n) {
    rep (j, h) {
      rep (k, w) {
        if (board[i][j][k] == '@') sx[i] = k, sy[i] = j;
      }
    }
  }
  rep (i, n) {
    queue<pint> que;
    que.push(pint(sx[i], sy[i]));
    vector<vector<bool>> reached(h, vector<bool>(w, false));
    reached[sy[i]][sx[i]] = true;
    while(!que.empty()) {
      auto c = que.front();
      que.pop();
      rep (j, 4) {
        ll nx = c.first + dx[j];
        ll ny = c.second + dy[j];
        if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
        if (board[i][ny][nx] == '#' || board[i][ny][nx] == 'x') continue;
        if (reached[ny][nx]) continue;
        reached[ny][nx] = true;
        que.push(pint(nx, ny));
      }
    }
    ll cnt = 0;
    rep (j, h) rep (k, w) if (reached[j][k] && board[i][j][k] == 'o') cnt++;
    p.push_back(pint(-cnt, i));
  }
  sort(ALL(p));
  rep (i, K) selected[i] = p[i].second;
  beamSearch();
  OUTPUT();
}