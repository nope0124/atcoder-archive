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
ll n = 500, m = 5000, d, v, x;
vector<ll> board(n + 1, 0);
vector<ll> dice = {1, 2, 3, 4, 5, 6};
ll sum = 0;
ll ans = 0;

void OUTPUT() {
  rep (i, 6) {
    if (i == 0) cout << dice[i];
    else cout << ' ' << dice[i];
  }
  cout << endl;
  fflush(stdout);
} 

void change(ll n) {
  rep (i, 6) {
    if (dice[i] != n) {
      dice[i] = n;
      break;
    }
  }
  return;
}

void changeMin(ll n) {
  vector<ll> tmp = dice;
  sort(ALL(tmp), greater<ll>());
  ll save = -1;
  rep (i, 6) {
    if (tmp[i] != n) {
      save = tmp[i];
      break;
    }
  }
  if (save == -1) return;
  rep (i, 6) {
    if (dice[i] == save) {
      dice[i] = n;
      break;
    }
  }
  return;
}

void changeMax(ll n) {
  vector<ll> tmp = dice;
  sort(ALL(tmp));
  ll save = -1;
  rep (i, 6) {
    if (tmp[i] != n) {
      save = tmp[i];
      break;
    }
  }
  if (save == -1) return;
  rep (i, 6) {
    if (dice[i] == save) {
      dice[i] = n;
      break;
    }
  }
  return;
}

void changeBase() {
  map<ll, ll> mp;
  ll from = -1, to = -1;
  rep (i, 6) mp[i + 1] = 0;
  rep (i, 6) mp[dice[i]]++;
  for (auto c: mp) {
    if (c.second == 0) {
      to = c.first;
    }
    if (c.second >= 2) {
      from = c.first;
    }
  }
  if (from == -1 && to == -1) return;
  rep (i, 6) {
    if (dice[i] == from) {
      dice[i] = to;
      return;
    }
  }
}

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  cin >> n >> m;
  bool flag = false;
  dice[5] = 1;
  while(m--) {
    OUTPUT();
    cin >> d >> v >> x;
    if (x - 3 >= 0) chmax(board[x - 3], v);
    if (x - 2 >= 0) chmax(board[x - 2], v);
    if (x - 1 >= 0) chmax(board[x - 1], v);
    chmax(board[x], v);
    if (x + 1 <= 500) chmax(board[x + 1], v);
    if (x + 2 <= 500) chmax(board[x + 2], v);
    if (flag) {
      if (n - 6 <= x && x <= n - 1) {
        changeMin(n - x);
      } else if (x >= 470) {
        changeBase();
      } else {
        
          changeMax(6);
        
      }
    } else {
      if (n - 6 <= x && x <= n - 1) {
        changeMin(n - x);
      } else if (x <= 470){
        change(6);
      } else {
        changeBase();
      }
      if (x == 500) flag = true;
    }
  }
}