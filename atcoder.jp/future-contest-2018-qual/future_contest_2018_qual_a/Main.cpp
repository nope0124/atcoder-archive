/* C++ */
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
  ll ans=0;
  while(n!=0) ans+=n%10,n/=10;
  return ans;
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

void dis(vector<ll> v){ rep(i,v.size()) cout<<v[i]<<endl; }

void dis2(vector<vector<ll>> v){
  rep(i,v.size()){
    rep(j,v[0].size()) cout<<v[i][j]<<' ';
    cout<<endl;
  }
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
vector<vector<ll>> a(100,vector<ll>(100));
vector<vector<ll>> eval(vector<ll> x,vector<ll> y,vector<ll> h){
  vector<vector<ll>> b(100,vector<ll>(100,0));
  rep(k,1000){
    rep(i,h[k]) rep(j,h[k]-i){
      ll tmp=h[k]-j-i;
      if(y[k]+i<100 && x[k]+j<100) b[y[k]+i][x[k]+j]+=tmp;
      if(y[k]+i<100 && 0<=x[k]-j) b[y[k]+i][x[k]-j]+=tmp;
      if(0<=y[k]-i && x[k]+j<100) b[y[k]-i][x[k]+j]+=tmp;
      if(0<=y[k]-i && 0<=x[k]-j) b[y[k]-i][x[k]-j]+=tmp;
    }
    Rep(j,h[k]){
      ll tmp=h[k]-j;
      if(x[k]+j<100) b[y[k]][x[k]+j]-=tmp;
      if(0<=x[k]-j) b[y[k]][x[k]-j]-=tmp;
    }
    Rep(i,h[k]){
      ll tmp=h[k]-i;
      if(y[k]+i<100) b[y[k]+i][x[k]]-=tmp;
      if(0<=y[k]-i) b[y[k]-i][x[k]]-=tmp;
    }
    b[y[k]][x[k]]-=3*h[k];
  }
  
  //rep(i,100) rep(j,100) rep(k,1000) b[i][j]+=max((ll)0,h[k]-abs(x[k]-j)-abs(y[k]-i));
  return b;
}

vector<vector<ll>> eval2(vector<vector<ll>> b,vector<ll> x,vector<ll> y,vector<ll> h,ll n,ll bx,ll by,ll bh){
  rep(i,h[n]) rep(j,h[n]-i){
    ll tmp=h[n]-j-i;
    if(y[n]+i<100 && x[n]+j<100) b[y[n]+i][x[n]+j]+=tmp;
    if(y[n]+i<100 && 0<=x[n]-j) b[y[n]+i][x[n]-j]+=tmp;
    if(0<=y[n]-i && x[n]+j<100) b[y[n]-i][x[n]+j]+=tmp;
    if(0<=y[n]-i && 0<=x[n]-j) b[y[n]-i][x[n]-j]+=tmp;
  }
  Rep(j,h[n]){
    ll tmp=h[n]-j;
    if(x[n]+j<100) b[y[n]][x[n]+j]-=tmp;
    if(0<=x[n]-j) b[y[n]][x[n]-j]-=tmp;
  }
  Rep(i,h[n]){
    ll tmp=h[n]-i;
    if(y[n]+i<100) b[y[n]+i][x[n]]-=tmp;
    if(0<=y[n]-i) b[y[n]-i][x[n]]-=tmp;
  }
  b[y[n]][x[n]]-=3*h[n];
  
  rep(i,bh) rep(j,bh-i){
    ll tmp=-bh+j+i;
    if(by+i<100 && bx+j<100) b[by+i][bx+j]+=tmp;
    if(by+i<100 && 0<=bx-j) b[by+i][bx-j]+=tmp;
    if(0<=by-i && bx+j<100) b[by-i][bx+j]+=tmp;
    if(0<=by-i && 0<=bx-j) b[by-i][bx-j]+=tmp;
  }
  Rep(j,bh){
    ll tmp=-bh+j;
    if(bx+j<100) b[by][bx+j]-=tmp;
    if(0<=bx-j) b[by][bx-j]-=tmp;
  }
  Rep(i,bh){
    ll tmp=-bh+i;
    if(by+i<100) b[by+i][bx]-=tmp;
    if(0<=by-i) b[by-i][bx]-=tmp;
  }
  b[by][bx]+=3*bh;
  
  return b;
}

ll score(vector<ll> x,vector<ll> y,vector<ll> h){
  ll ans=0;
  vector<vector<ll>> b=eval(x,y,h);
  rep(i,100) rep(j,100) ans+=abs(a[i][j]-b[i][j]);
  return ans;
}
ll score2(vector<vector<ll>> b,vector<ll> x,vector<ll> y,vector<ll> h,ll n,ll bx,ll by,ll bh){
  ll ans=0;
  vector<vector<ll>> nb=eval2(b,x,y,h,n,bx,by,bh);
  rep(i,100) rep(j,100) ans+=abs(a[i][j]-nb[i][j]);
  return ans;
}
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  vector<ll> x,y,h;
  ll cnt=162500;
  rep(i,100) rep(j,100) cin>>a[i][j];
  rep(i,1000){
    x.push_back(rand()%100);
    y.push_back(rand()%100);
    h.push_back(rand()%100+1);
  }
  vector<vector<ll>> b=eval(x,y,h);
  ll ans=score(x,y,h);
  rep(_,cnt){
    ll n=rand()%1000;
    ll bx,by,bh;
    bx=x[n];
    by=y[n];
    bh=h[n];
    x[n]=min((ll)99,max((ll)0,x[n]+(rand()%3)-1));
    y[n]=min((ll)99,max((ll)0,y[n]+(rand()%3)-1));
    h[n]=min((ll)100,max((ll)1,h[n]+(rand()%3)-1));
    ll tmp=score2(b,x,y,h,n,bx,by,bh);
    if(ans>tmp){
      ans=tmp;
      b=eval2(b,x,y,h,n,bx,by,bh);
    }else{
      x[n]=bx;
      y[n]=by;
      h[n]=bh;
    }
  }
  
  cout<<1000<<endl;
  //cout<<200000000-ans<<endl;
  rep(i,1000){
    cout<<x[i]<<' '<<y[i]<<' '<<h[i]<<'\n';
  }
}