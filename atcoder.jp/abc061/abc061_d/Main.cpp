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

/* ベルマンフォード法 */

struct edge{ll from,to,cost;};
edge graph[100010];
ll d[100010];
ll V,E;
bool negative=false;
void bellman_ford(ll s){
  rep(i,V) d[i]=1e16;
  d[s]=0;
  rep(i,V){
    bool update=false;
    rep(j,E){
      edge e=graph[j];
      if(d[e.to]>d[e.from]+e.cost && d[e.from]!=1e16){
        d[e.to]=d[e.from]+e.cost;
        update=true;
      }
    }
    if(!update) break;
    if(i==V-1) negative=true;
  }
}
/*V,Eがmain関数に定義されていると動かない*/
/*ダイクストラ法とedgeの使い方が違う*/
/*http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4425536#1…参考*/

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  cin>>V>>E;
  vector<ll> a(E),b(E),c(E);
  rep(i,E) cin>>a[i]>>b[i]>>c[i],a[i]--,b[i]--,c[i]*=-1;
  vector<bool> v1(V,false),v2(V,false),ans(V,false);
  vector<ll> g1[V],g2[V];
  rep(i,E) g1[a[i]].push_back(b[i]),g2[b[i]].push_back(a[i]);
  queue<ll> que;
  v1[0]=true;
  que.push(0);
  while(!que.empty()){
    auto c=que.front();que.pop();
    for(auto tmp:g1[c]){
      if(!v1[tmp]){
        v1[tmp]=true;
        que.push(tmp);
      }
    }
  }
  v2[V-1]=true;
  que.push(V-1);
  while(!que.empty()){
    auto c=que.front();que.pop();
    for(auto tmp:g2[c]){
      if(!v2[tmp]){
        v2[tmp]=true;
        que.push(tmp);
      }
    }
  }
  rep(i,V) if(v1[i] && v2[i]) ans[i]=true;
  rep(i,E){
    if(!ans[a[i]] || !ans[b[i]]) continue;
    graph[i]=edge{a[i],b[i],c[i]};
  }
  bellman_ford(0);
  if(negative) cout<<"inf"<<endl;
  else cout<<d[V-1]*-1<<endl;
}