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
  for(ll i=0;i<v.size();i++) n+=v[i];
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
  for(ll i=0;i<s.size()-1;i++){
    if(s[i]==s[i+1]){
      x++;
      if(i==s.size()-2){
        p.push_back(pair<char,ll>(s[i],x));
      }
    }else{
      p.push_back(pair<char,ll>(s[i],x));
      x=1;
      if(i==s.size()-2){
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

const int MAX_N=100010;
vector<bool> sieve_of_eratosthenes(){
  vector<bool> isPrime(MAX_N+1,true);
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
ll INF=1e16;
ll n;
vector<pint> g[100010],g2[100010];
ll d[100010],d2[100010];

void dijkstra(ll s){
  priority_queue<pint,vector<pint>,greater<pint>> que;
  fill(d,d+n,INF);
  d[s]=0;
  que.push(pint(0,s));
  while(!que.empty()){
    auto p=que.top();
    que.pop();
    ll v=p.second;
    if(d[v]<p.first) continue;
    for(auto e:g[v]){
      if(d[e.first]>d[v]+e.second){
        d[e.first]=d[v]+e.second;
        que.push(pint(d[e.first],e.first));
      }
    }
  }
}
void dijkstra2(ll s){
  priority_queue<pint,vector<pint>,greater<pint>> que;
  fill(d2,d2+n,INF);
  d2[s]=0;
  que.push(pint(0,s));
  while(!que.empty()){
    auto p=que.top();
    que.pop();
    ll v=p.second;
    if(d2[v]<p.first) continue;
    for(auto e:g2[v]){
      if(d2[e.first]>d2[v]+e.second){
        d2[e.first]=d2[v]+e.second;
        que.push(pint(d2[e.first],e.first));
      }
    }
  }
}
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll m,s,t;
  cin>>n>>m>>s>>t;s--;t--;
  ll dp[n];
  rep(i,m){
    ll u,v,a,b;cin>>u>>v>>a>>b;u--;v--;
    g[u].push_back(pint(v,a));
    g[v].push_back(pint(u,a));
    g2[u].push_back(pint(v,b));
    g2[v].push_back(pint(u,b));
  }
  dijkstra(s);
  dijkstra2(t);
  rep(i,n) dp[i]=d[i]+d2[i];
  vector<ll> dp2(n);
  rep(i,n) dp2[i]=dp[i];
  reverse(ALL(dp2));
  ll tmp=dp2[0];
  rep(i,n){
    if(dp2[i]<tmp) tmp=dp2[i];
    dp2[i]=tmp;
  }
  reverse(ALL(dp2));
  rep(i,n){
    cout<<1000000000000000-dp2[i]<<endl;
  }
  
}