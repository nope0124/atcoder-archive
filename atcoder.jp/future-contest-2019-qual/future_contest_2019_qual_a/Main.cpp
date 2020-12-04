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
vector<pint> p(500),tp(500);
vector<vector<vector<bool>>> reached(500,vector<vector<bool>>(29,vector<bool>(29,false)));
vector<vector<vector<bool>>> treached(500,vector<vector<bool>>(29,vector<bool>(29,false)));
/*bool cmp(pint a, pint b) { return a.second < b.second; }*/
vector<string> init(){
  vector<string> ret(29);
  ret[0]="#############################";
  ret[28]="#############################";
  rep(i,27) ret[i+1]="#...........................#";
  return ret;
}
void output(vector<string> v){
  rep(i,29) cout<<v[i]<<'\n';
}
ll score(vector<vector<ll>> v){ //10^3
  ll ret=0;
  rep(i,29) rep(j,29){
    if(v[i][j]==1) ret+=10;
    else if(v[i][j]==2) ret+=3;
    else if(v[i][j]==3) ret++;
  }
  return ret;
}

vector<vector<ll>> simulate(vector<string> v,vector<string> board){ //10^6
  vector<vector<ll>> ret(29,vector<ll>(29,0));
  vector<pint> d={pint(0,-1),pint(-1,0),pint(0,1),pint(1,0)};
  rep(i,500){
    ll dir=0;
    ll x=14,y=14;
    reached[i][y][x]=true;
    rep(j,300){
      if(board[y][x]=='R' && v[i][j]=='L') dir=(dir+3)%4;
      else if(board[y][x]=='L' && v[i][j]=='R') dir=(dir+1)%4;
      else if(v[i][j]=='L') dir=(dir+1)%4;
      else if(v[i][j]=='R') dir=(dir+3)%4;
      else if(v[i][j]=='S'){
        ll dx=d[dir].first;
        ll dy=d[dir].second;
        if(x+dx<1 || x+dx>=28 || y+dy<1 || y+dy>=28) continue;
        x+=dx;
        y+=dy;
      }
      reached[i][y][x]=true;
    }
    ret[y][x]++;
    p[i]=pint(x,y);
  }
  return ret;
}

void reset(ll n){ //10^3
  rep(i,29) rep(j,29) reached[n][i][j]=false;
}
void treset(ll n){ //10^3
  rep(i,29) rep(j,29) treached[n][i][j]=false;
}

vector<ll> tv;
vector<vector<ll>> simulate_one(vector<string> v,vector<string> board,vector<vector<ll>> cnt,ll nx,ll ny){ //10^6
  vector<vector<ll>> ret=cnt;
  vector<pint> d={pint(0,-1),pint(-1,0),pint(0,1),pint(1,0)};
  tv.clear();
  rep(i,500){
    if(!reached[i][ny][nx]) continue;
    tv.push_back(i);
  }
  rep(i,tv.size()) treset(tv[i]),tp[tv[i]]=p[tv[i]];
  rep(i,tv.size()) ret[p[tv[i]].second][p[tv[i]].first]--;
  rep(i,tv.size()){
    ll dir=0;
    ll x=14,y=14;
    treached[tv[i]][y][x]=true;
    rep(j,300){
      if(board[y][x]=='R' && v[tv[i]][j]=='L') dir=(dir+3)%4;
      else if(board[y][x]=='L' && v[tv[i]][j]=='R') dir=(dir+1)%4;
      else if(v[tv[i]][j]=='L') dir=(dir+1)%4;
      else if(v[tv[i]][j]=='R') dir=(dir+3)%4;
      else if(v[tv[i]][j]=='S'){
        ll dx=d[dir].first;
        ll dy=d[dir].second;
        if(x+dx<1 || x+dx>=28 || y+dy<1 || y+dy>=28) continue;
        x+=dx;
        y+=dy;
      }
      treached[tv[i]][y][x]=true;
    }
    ret[y][x]++;
    tp[tv[i]]=pint(x,y);
  }
  return ret;
}

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main(){
  IOS;
  ll loop=13400;
  ll n,m,l;cin>>n>>m>>l;
  vector<string> v(500);
  rep(i,500) cin>>v[i];
  vector<string> board=init();
  vector<vector<ll>> cnt=simulate(v,board);
  ll ans=score(cnt);
  rep(i,loop){
    vector<char> c={'R','L'};
    ll x=rand()%27+1;
    ll y=rand()%27+1;
    char bc=board[y][x];
    board[y][x]=c[rand()%2];
    vector<vector<ll>> tcnt=simulate_one(v,board,cnt,x,y);
    ll tmp=score(tcnt);
    if(ans<tmp){
      ans=tmp;
      cnt=tcnt;
      rep(j,tv.size()) reached[tv[j]]=treached[tv[j]],p[tv[j]]=tp[tv[j]];
    }else{
      board[y][x]=bc;
    }
  }
  /*rep(i,29){
    rep(j,29) cout<<cnt[i][j];
    cout<<endl;
  }*/
  //cout<<ans<<endl;
  output(board);
}