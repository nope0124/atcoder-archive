/**Function Template**/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pint;
const int MAX = 510000;
const int MOD = 1000000007;
#define rep(i, n) for(ll i = ll(0); i < ll(n); i++)
#define Rep(i, n) for(ll i = ll(1); i < ll(n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265358979323846
#define ifYN(x) cout<<(x?"Yes":"No")<<"\n" 
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

bool palindrome(string s){
  bool flag=true;
  rep(i,(ll)s.size()) if(s[i]!=s[s.size()-1-i]) flag=false;
  return flag;
}

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }

}
ll Len(ll n) {
  ll s=0;
  while(n!=0) s++, n/=10;
  return s;
}


ll Sint(ll n) {
  ll m=0,s=0,a=n;
  while(a!=0) s++, a/=10;
  for(ll i=s-1;i>=0;i--) m+=n/((ll)pow(10,i))-(n/((ll)pow(10,i+1)))*10;
  return m;
}


ll Svec(vector<ll> v){
  ll n=0;
  rep(i,(ll)v.size()) n+=v[i];
  return n;
}


ll GCD(ll a,ll b) {
  return b ? GCD(b,a%b) : a;
}


ll LCM(ll a,ll b){
  return a/GCD(a,b)*b;
}


ll Factorial(ll n){
  ll m=1;
  while(n>=1) m*=n,n--;
  return m;
}

void runlength(string s,vector<pair<char,ll>> &p){
  ll x=1;
  if(s.size()==1){
    p.push_back(pair<char,ll>(s[0],1));
  }
  rep(i,(ll)s.size()-1){
    if(s[i]==s[i+1]){
      x++;
      if(i==(ll)s.size()-2){
        p.push_back(pair<char,ll>(s[i],x));
      }
    }else{
      p.push_back(pair<char,ll>(s[i],x));
      x=1;
      if(i==(ll)s.size()-2){
        p.push_back(pair<char,ll>(s[s.size()-1],x));
      }
    }
  }
}

ll COM(ll n,ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

string Toupper(string s){
  string ans="";
  rep(i,s.size()){
    if('a'<=s[i] && s[i]<='z') ans+=(char)s[i]-32;
    else ans+=s[i];
  }
  return ans;
}
string Tolower(string s){
  string ans="";
  rep(i,s.size()){
    if('A'<=s[i] && s[i]<='Z') ans+=(char)s[i]+32;
    else ans+=s[i];
  }
  return ans;
}


const int MAX_N=100010;
vector<bool> sieve_of_eratosthenes(){
  vector<bool> isPrime(MAX_N+1,true);
  /* isPrime[1]=false; */
  for(int i=2;i<=MAX_N;i++){
    if(isPrime[i]){
      for(int j=2*i;j<=MAX_N;j+=i){
        isPrime[j]=false;
      }
    }
  }
  return isPrime;
}

vector<pint> prime_factorize(ll n){
  vector<pint> ans;
  for(ll p=2;p<=sqrt(n);p++){
    if(n%p!=0) continue;
    ll cnt=0;
    while(n%p==0){
      n/=p;
      cnt++;
    }
    ans.push_back(make_pair(p,cnt));
  }
  if(n!=1) ans.push_back(make_pair(n,1));
  return ans;
}

/*bool cmp(pint a, pint b) { return a.second < b.second; }*/

const int MAX_V=310;
typedef pair<ll,ll> pint;
ll pre[MAX_V];
ll V;
ll INF=1e16;
ll cost[310][310];
ll dist[MAX_V];
ll used[MAX_V];

void dijkstra(ll s){
  priority_queue<pint,vector<pint>,greater<pint>> que;
  fill(dist,dist+V,INF);
  fill(used,used+V,false);
  fill(pre,pre+V,-1);
  dist[s]=0;
  while(1){
    ll v=-1;
    rep(i,V) if(!used[i] && (v==-1 || dist[i]<dist[v])) v=i;
    if(v==-1) break;
    used[v]=true;
    rep(i,V){
      if(dist[i]>dist[v]+cost[v][i]){
        dist[i]=dist[v]+cost[v][i];
        pre[i]=v;
      }
    }
  }
}
vector<ll> get_path(ll t){
  vector<ll> path;
  for(;t!=-1;t=pre[t]) path.push_back(t);
  reverse(ALL(path));
  return path;
}


/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll m;
  cin>>V>>m;
  vector<ll> a(m),b(m),c(m);
  rep(i,m) cin>>a[i]>>b[i]>>c[i],a[i]--,b[i]--;
  rep(i,310) rep(j,310) cost[i][j]=INF;
  rep(i,310) cost[i][i]=0;
  rep(i,m){
    cost[a[i]][b[i]]=c[i];
    cost[b[i]][a[i]]=c[i];
  }
  ll ans=INF;
  dijkstra(0);
  vector<ll> v(V);
  rep(i,V) v[i]=dist[i];
  vector<vector<ll>> w(V);
  rep(i,V) w[i]=get_path(i);
  Rep(i,V){
    rep(j,w[i].size()-1) cost[w[i][j+1]][w[i][j]]=INF;
    dijkstra(i);
    ll tmp=dist[0]+v[i];
    chmin(ans,tmp);
    rep(j,w[i].size()-1) cost[w[i][j+1]][w[i][j]]=cost[w[i][j]][w[i][j+1]];
  }
  if(ans==INF) cout<<-1<<endl;
  else cout<<ans<<endl;
}