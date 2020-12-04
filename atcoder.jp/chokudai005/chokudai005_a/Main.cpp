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

/*bool cmp(pint a, pint b) { return a.second < b.second; }*/
struct ANSWER{ll y, x, c;};
vector<ANSWER> ans;
vector<ANSWER> nans;
ll id, n = 100, k = 9;
vector<string> save(n);
vector<string> board(n, "....................................................................................................");
ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0, 0, -1, 1};
map<ll, ll> mp;
ll ni = 1;
void simulate(ll x, ll y, ll c) {
  x--; y--;
  mp.clear();
  char type = board[y][x];
  vector<vector<ll>> flag(n, vector<ll>(n, INF));
  flag[y][x] = 0;
  deque<pint> que;
  que.push_front(pint(x, y));
  while(!que.empty()) {
    auto p = que.front();que.pop_front();
    rep (i, 4) {
      ll nx = p.first + dx[i];
      ll ny = p.second + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (board[ny][nx] != type && board[ny][nx] != 'A' + c - 1) {
        continue;
      }
      if (flag[ny][nx] != INF) continue;
      if (board[ny][nx] == board[p.second][p.first]) {
		flag[ny][nx] = flag[p.second][p.first];
        que.push_front(pint(nx, ny));
      } else {
        flag[ny][nx] = flag[p.second][p.first] + 1;
        que.push_back(pint(nx, ny));
      }
    }
  }
  rep (i, n) {
    rep (j, n) {
      if (flag[i][j] <= 1) {
        board[i][j] = 'A' + c - 1;
        rep (k, 4) {
          ll nx = j + dx[k];
          ll ny = i + dy[k];
          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (board[ny][nx] == type || board[ny][nx] == 'A' + c - 1) continue;
          mp[board[ny][nx] - 'A' + 1]++;
        }
      }
    }
  }
  ll tmp = 0;
  for (auto p: mp) {
    if (tmp < p.second) {
      tmp = p.second;
      ni = p.first;
    }
  }
  ans.push_back(ANSWER{y + 1, x + 1, c});
}

bool verify() {
  char type = board[0][0];
  rep (i, n) rep (j, n) {
    if (board[i][j] != type) return false;
  }
  return true;
}

void prepro() {
  Rep (i, n - 1) {
    Rep (j, n - 1) {
      char type;
      bool flag = true;
      rep (k, 4) {
        ll nx = j + dx[k];
        ll ny = i + dy[k];
        if (k == 0) type = board[ny][nx];
        else if (type != board[ny][nx]) flag = false;
      }
      if (flag && board[i][j] != type) {
        ans.push_back(ANSWER{i + 1, j + 1, type - 'A' + 1});
        board[i][j] = type;
      }
    }
  }
}

void OUTPUT(vector<ANSWER> ans) {
  cout << ans.size() << endl;
  rep (i, ans.size()) cout << ans[i].y << ' ' << ans[i].x << ' ' << ans[i].c << endl;
}

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  cin >> id >> n >> k;
  rep (i, n) cin >> save[i];
  rep (i, 1000) nans.push_back(ANSWER{1, 1, 1});
  rep (i, 9) {
    ni = i + 1;
    bool flag = true;
    rep (i, n) rep (j, n) board[i][j] = 'A' + save[i][j] - '1';
    prepro();
    while (flag) {
      simulate(n / 2, n / 2, ni);
      if (verify()) {
        flag = false;
        break;
      }
    }
    if (ans.size() < nans.size()) {
      nans = ans;
    }
    ans.clear();
  }
  OUTPUT(nans);
}