/*Function Template*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 510000;
const int MOD = 1000000007;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll fac[MAX], finv[MAX], inv[MAX];
const long long INF=1LL<<58;
template<class T> int former(const vector<T> &v, T x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
}
template<class T> int latter(const vector<T> &v, T x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}
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


ll GCD(ll a,ll b){
  ll r,tmp;
/*自然数 a > b を確認・入替*/
  if(a<b){
    tmp=a,a=b,b=tmp;
  }
/*ユークリッドの互除法*/
  r=a%b;
  while(r!=0){
    a=b,b=r,r=a%b;
  }
  return b;
}


ll LCM(ll a,ll b){
  ll c=a,d=b,r,tmp;
/*自然数 a > b を確認・入替*/
  if(a<b){
    tmp=a,a=b,b=tmp;
  }
/*ユークリッドの互除法*/
  r=a%b;
  while(r!=0){
    a=b,b=r,r=a%b;
  }
  return c/b*d;
}


ll Factorial(ll n){
  ll m=1;
  while(n>=1) m*=n,n--;
  return m;
}

vector<pair<char,ll>> runlength(string s,vector<pair<char,ll>> p){
  ll x=1;
  if(s.size()==1){
    p.push_back(pair<char,ll>(s[0],1));
    return p;
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
  return p;
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

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll a,b,q;
  cin>>a>>b>>q;
  vector<ll> s(a),t(b);
  rep(i,a) cin>>s[i];
  rep(i,b) cin>>t[i];
  s.push_back(INF);s.push_back(-INF);sort(ALL(s));
  t.push_back(INF);t.push_back(-INF);sort(ALL(t));
  rep(_,q){
    ll x;cin>>x;
    ll res=INF;
    rep(i,2){
      ll first=(i?s[former(s,x)]:s[latter(s,x)]);
      rep(j,2){
        ll second=(j?t[former(t,first)]:t[latter(t,first)]);
        chmin(res,abs(x-first)+abs(first-second));
      }
    }
    rep(i,2){
      ll first=(i?t[former(t,x)]:t[latter(t,x)]);
      rep(j,2){
        ll second=(j?s[former(s,first)]:s[latter(s,first)]);
        chmin(res,abs(x-first)+abs(first-second));
      }
    }
    cout<<res<<endl;
  }
}