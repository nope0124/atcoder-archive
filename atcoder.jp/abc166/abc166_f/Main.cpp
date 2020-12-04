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

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll n,A,B,C;
  cin>>n>>A>>B>>C;
  vector<ll> a(n+1,0),b(n+1,0),c(n+1,0);
  vector<string> s(n);
  vector<char> anss;
  rep(i,n) cin>>s[i];
  reverse(ALL(s));
  rep(i,n){
    if(s[i]=="AB"){
      a[i+1]=a[i]+1;
      b[i+1]=b[i]+1;
    }else if(s[i]=="BC"){
      c[i+1]=c[i]+1;
      b[i+1]=b[i]+1;
    }else if(s[i]=="AC"){
      a[i+1]=a[i]+1;
      c[i+1]=c[i]+1;
    }
  }
  reverse(ALL(a));reverse(ALL(b));reverse(ALL(c));reverse(ALL(s));
  bool flaga=false,flagb=false,flagc=false;
  rep(i,n){
    if(s[i]=="AB"){
      
      
      if(A==0 && B==0){
        cout<<"No"<<endl;
        return 0;
      }else if(A==0){
        A++;
        B--;
        anss.push_back('A');
      }else if(B==0){
        A--;
        B++;
        anss.push_back('B');
      }else{
      
      
        if((A-a[i])>=(B-b[i])){
          A--;
          B++;
          anss.push_back('B');
        }else{
          A++;
          B--;
          anss.push_back('A');
        }
      
      }
      
    }else if(s[i]=="BC"){
      if(B==0 && C==0){
        cout<<"No"<<endl;
        return 0;
      }else if(B==0){
        B++;
        C--;
        anss.push_back('B');
      }else if(C==0){
        B--;
        C++;
        anss.push_back('C');
      }else{
        if((B-b[i])>=(C-c[i])){
          B--;
          C++;
          anss.push_back('C');
        }else{
          B++;
          C--;
          anss.push_back('B');
        }
      }
    }else if(s[i]=="AC"){
      
      if(C==0 && A==0){
        cout<<"No"<<endl;
        return 0;
      }else if(C==0){
        C++;
        A--;
        anss.push_back('C');
      }else if(A==0){
        C--;
        A++;
        anss.push_back('A');
      }else{
      
      
        if((C-c[i])>=(A-a[i])){
          C--;
          A++;
          anss.push_back('A');
        }else{
          C++;
          A--;
          anss.push_back('C');
        }
        
      }
      
    }
  }
  cout<<"Yes"<<endl;
  rep(i,n) cout<<anss[i]<<endl;
}