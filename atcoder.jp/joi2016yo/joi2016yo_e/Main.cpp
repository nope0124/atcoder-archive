/**Function Template**/
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
  rep(i,s.size()) if(s[i]!=s[s.size()-1-i]) flag=false;
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
/* ダイクストラ法 */

const int MAX_V=100010;
struct edge{ll to,cost;};
typedef pair<ll,ll> pint;
ll n;
ll INF=1e16;
vector<edge> graph[MAX_V];
ll dist[MAX_V];
void dijkstra(ll s){
  priority_queue<pint,vector<pint>,greater<pint>> que;
  fill(dist,dist+n,INF);
  dist[s]=0;
  que.push(pint(0,s));
  while(!que.empty()){
    auto p=que.top();que.pop();
    ll v=p.second;
    if(dist[v]<p.first) continue;
    for(auto e:graph[v]){
      if(dist[e.to]>dist[v]+e.cost){
        dist[e.to]=dist[v]+e.cost;
        que.push(pint(dist[e.to],e.to));
      }
    }
  }
}
/*nがmain関数に定義されていると動かない*/
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll m,k,s,p,q;
  cin>>n>>m>>k>>s>>p>>q;
  queue<ll> que;
  vector<ll> v(n,-1);
  vector<ll> flag(n,0);
  rep(i,k){
    ll tmp;cin>>tmp;tmp--;
    que.push(tmp);
    v[tmp]=0;
    flag[tmp]=2;
  }
  vector<ll> g[n];
  vector<ll> a(m),b(m);
  rep(i,m){
    cin>>a[i]>>b[i];a[i]--;b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  while(!que.empty()){
    auto c=que.front();que.pop();
    for(auto tmp:g[c]){
      if(v[tmp]==-1){
        v[tmp]=v[c]+1;
        que.push(tmp);
      }
    }
  }
  rep(i,n) if(0<=v[i] && v[i]<=s && flag[i]==0) flag[i]=1;
  rep(i,m){
    if(b[i]==n-1){
      graph[a[i]].push_back(edge{b[i],0});
    }else{
      if(flag[b[i]]==0){
        graph[a[i]].push_back(edge{b[i],p});
      }else if(flag[b[i]]==1){
        graph[a[i]].push_back(edge{b[i],q});
      }else if(flag[b[i]]==2){
        graph[a[i]].push_back(edge{b[i],10000000000000000});
      }
      if(flag[a[i]]==0){
        graph[b[i]].push_back(edge{a[i],p});
      }else if(flag[a[i]]==1){
        graph[b[i]].push_back(edge{a[i],q});
      }else if(flag[a[i]]==2){
        graph[b[i]].push_back(edge{a[i],10000000000000000});
      }
    }
  }
  dijkstra(0);
  cout<<dist[n-1]<<endl;
}