/*Function Template*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pint;
const int MAX = 510000;
const int MOD = 1000000007;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define Rep(i, n) for(ll i = 1; i < (n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265358979323846
ll fac[MAX], finv[MAX], inv[MAX];


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

bool cmp(pint a, pint b) { return a.second < b.second; }
vector<ll> g[100010];
vector<ll> value(100010,0);
vector<pint> pp;
map<pint,ll> mp;
ll cnt=0;

void dfs(ll p,ll v){
    ll ans=value[v];
    for(auto c:g[v]){
        if(c==p) continue;
        ans++;
        if(p!=-1 && ans==value[v]) ans++;
        value[c]=ans%cnt;
        pp.push_back(pint(value[c],mp[pint(v,c)]));
        dfs(v,c);
    }
}


/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll n;
  cin>>n;
  rep(i,n-1){
      ll a,b;cin>>a>>b;a--;b--;
      g[a].push_back(b);
      g[b].push_back(a);
      mp[pint(a,b)]=i;
      mp[pint(b,a)]=i;
  }
  rep(i,n) chmax(cnt,(ll)(g[i].size()));
  ll res=0;
  dfs(-1,0);
  sort(ALL(pp),cmp);
  cout<<cnt<<endl;
  rep(i,n-1) cout<<pp[i].first+1<<endl;
}