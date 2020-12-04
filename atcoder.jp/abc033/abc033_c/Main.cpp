/*Function Template*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1000000007;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


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



/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  IOS;
  ll ans=0;
  string s;
  cin>>s;
  vector<int> v;
  vector<string> a;
  rep(i,s.size()){
    if(s[i]=='+') v.push_back(i+1);
  }
  if(v.size()>=1){
    rep(i,v.size()+1){
      if(i==0){
        a.push_back(s.substr(0,v[0]-1));
      }else if(i==v.size()){
        a.push_back(s.substr(v[v.size()-1],s.size()-v[v.size()-1]));
      }else{
        a.push_back(s.substr(v[i-1],v[i]-v[i-1]-1));
      }
    }
    rep(i,a.size()){
      bool flag=false;
      rep(j,a[i].size()){
        if(a[i][j]=='0') flag=true;
      }
      if(flag) ans+=1;
    }
    cout<<a.size()-ans<<endl;
    return 0;
  }else{
    bool flag=false;
    rep(i,s.size()){
      if(s[i]=='0') flag=true;
    }
    if(flag){
      cout<<0<<endl;
    }else{
      cout<<1<<endl;
    }
    return 0;
  }
  
}