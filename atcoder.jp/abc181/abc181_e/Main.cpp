/* C++ */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pint;
const ll MAX = 510000;
const ll MOD = 1000000007;
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

ll POW(ll a, ll n) {
  ll ret = 1;
  rep (i, n) ret *= a;
  return ret;
}

/* 累積和 */
vector<ll> acc_sum(vector<ll> v){
  vector<ll> ans(v.size(), 0);
  ans[0] = v[0];
  rep(i,v.size() - 1) ans[i+1]=ans[i]+v[i + 1];
  return ans;
}

/* 二次元累積和 */
vector<vector<ll>> two_acc_sum(vector<vector<ll>> v){
  ll h=v.size();
  ll w=v[0].size();
  vector<vector<ll>> ans(h+1,vector<ll>(w+1,0));
  rep(i,h) rep(j,w) ans[i+1][j+1]=ans[i][j+1]+ans[i+1][j]-ans[i][j]+v[i][j];
  return ans;
}
/* 空の配列でRE */

/* 二次元累積和全探索(最大値、面積) */
pint two_acc_sum_search(vector<vector<ll>> v){
  // O(1/4*h*h*w*w)
  ll ans=0;
  ll tmp=0;
  ll h=v.size()-1;
  ll w=v[0].size()-1;
  rep(i,h) for(ll ii=i;ii<h;ii++){
    rep(j,w) for(ll jj=j;jj<w;jj++){
      chmax(ans,v[ii+1][jj+1]+v[i][j]-v[ii+1][j]-v[i][jj+1]);
      chmax(tmp,(ii+1-i)*(jj+1-j));
    }
  }
  pint p={ans,tmp};
  return p;
}
/* 空の配列でRE */
/* 変数が被らないように */

/*bool cmp(pint a, pint b) { return a.second < b.second; }*/
ll INF = 1e16;
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll n, m; cin >> n >> m;
  vector<ll> h(n), w(m);
  rep (i, n) cin >> h[i];
  rep (i, m) cin >> w[i];
  sort(ALL(h));
  vector<ll> dif1(n / 2 + 1, INF);
  vector<ll> dif2(n / 2 + 1, INF);
  rep (i, n / 2) dif1[i] = abs(h[2 * i] - h[2 * i + 1]);
  rep (i, n / 2) dif2[i] = abs(h[n - 2 * i - 1] - h[n - 2 * i - 2]);
  vector<ll> sum1 = acc_sum(dif1);
  vector<ll> sum2 = acc_sum(dif2);
  reverse(ALL(sum2));
  ll ans = INF;
  rep (i, m) {
    ll tmp = (upper_bound(ALL(h), w[i]) - h.begin());
    if (tmp % 2 == 0) {
      ll sum = 0;
      if (tmp / 2 - 1 >= 0) sum += sum1[(tmp / 2 - 1)];
      if (tmp / 2 + 1 < (n + 1) / 2) sum += sum2[tmp / 2 + 1];
      sum += abs(h[tmp] - w[i]);
      chmin(ans, sum);
    } else {
      ll sum = 0;
      if ((tmp - 1) / 2 - 1 >= 0) sum += sum1[((tmp - 1) / 2 - 1)];
      if ((tmp + 1) / 2 < (n + 1) / 2) sum += sum2[(tmp + 1) / 2];
      sum += abs(h[tmp - 1] - w[i]);
      chmin(ans, sum);
    }
  }
  cout << ans << endl;
}