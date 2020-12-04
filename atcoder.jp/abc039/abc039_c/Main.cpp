/*Function Template*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1000000007;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define ALL(a)  (a).begin(),(a).end()


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
  ios::sync_with_stdio(false);
  string s="WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
  string n;
  ll ans=0;
  cin>>n;
  rep(i,20){
    if(s[i]=='W') ans++; 
    if(n==s.substr(i,20)) break;
  }
  if(ans%7==1){
    cout<<"Do"<<endl;
  }else if(ans%7==2){
    cout<<"Re"<<endl;
  }else if(ans%7==3){
    cout<<"Mi"<<endl;
  }else if(ans%7==4){
    cout<<"Fa"<<endl;
  }else if(ans%7==5){
    cout<<"So"<<endl;
  }else if(ans%7==6){
    cout<<"La"<<endl;
  }else if(ans%7==0){
    cout<<"Si"<<endl;
  }
}