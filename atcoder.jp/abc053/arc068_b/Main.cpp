#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for(ll i = 0; i < (n); i++)
int main(){
  ll n,ans=0,tmp=0;
  cin>>n;
  map<ll,ll> mp;
  rep(i,n){
    ll a;cin>>a;mp[a]++;
  }
  for(auto c:mp){
    if(c.second%2==0){
      mp[c.first]=0;
      tmp++;
    }else{
      mp[c.first]=1;
    }
  }
  ans+=(tmp/2)*2;
  for(auto c:mp){
    ans+=c.second;
  }
  cout<<ans<<endl;
}