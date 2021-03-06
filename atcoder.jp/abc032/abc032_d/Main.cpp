/**C++**/
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

bool cmp(pint a, pint b) { return a.second < b.second; }

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll n,m,ans=0;
  cin>>n>>m;
  vector<ll> v(n),w(n);
  rep(i,n) cin>>v[i]>>w[i];
  ll flag=0;
  if(flag==0 && n<=30) flag=1;
  ll vmax=0,wmax=0;
  rep(i,n) chmax(vmax,v[i]),chmax(wmax,w[i]);
  if(flag==0 && wmax<=1000) flag=2;
  if(flag==0 && vmax<=1000) flag=3;
  if(flag==1){
    ll n1=n/2;
    ll n2=n-n1;
    vector<pint> p;
    rep(bit,(1<<n1)){
      ll cnt=0;
      ll sum=0;
      rep(i,n1) if(bit&(1<<i)){
        sum+=v[i];
        cnt+=w[i];
      }
      if(cnt>m) continue;
      p.push_back(pint(cnt,sum));
    }
    sort(ALL(p));
    vector<pint> pp;
    ll pre=1e16;
    for(ll i=p.size()-1;i>=0;i--){
      if(pre!=p[i].first){
        pp.push_back(pint(p[i].first,p[i].second));
      }
      pre=p[i].first;
    }
    sort(ALL(pp));
    vector<pint> np;
    pre=-1;
    rep(i,pp.size()){
      if(pre<pp[i].second){
        np.push_back(pint(pp[i].first,pp[i].second));
        pre=pp[i].second;
      }
    }
    sort(ALL(np));
    vector<ll> nv(np.size()),nw(np.size());
    rep(i,np.size()) nv[i]=np[i].second,nw[i]=np[i].first;
    rep(bit,(1<<n2)){
      ll cnt=0;
      ll sum=0;
      rep(i,n2) if(bit&(1<<i)){
        cnt+=w[i+n1];
        sum+=v[i+n1];
      }
      if(cnt>m) continue;
      chmax(ans,nv[upper_bound(ALL(nw),m-cnt)-nw.begin()-1]+sum);
    }
  }else if(flag==2){
    ll sum=Svec(w);
    vector<vector<ll>> dp(n+1,vector<ll>(sum+1,0));
    rep(i,n){
      rep(j,sum+1){
        if(j-w[i]>=0) dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
        else chmax(dp[i+1][j],dp[i][j]);
      }
    }
    rep(i,sum+1) if(i<=m) chmax(ans,dp[n][i]);
  }else if(flag==3){
    ll sum=Svec(v);
    vector<vector<ll>> dp(n+1,vector<ll>(sum+1,1e16));
    dp[0][0]=0;
    rep(i,n){
      rep(j,sum+1){
        if(j-v[i]>=0) dp[i+1][j]=min(dp[i][j],dp[i][j-v[i]]+w[i]);
        else chmin(dp[i+1][j],dp[i][j]);
      }
    }
    rep(i,sum+1) if(dp[n][i]<=m) chmax(ans,i);
  }
  cout<<ans<<endl;
}