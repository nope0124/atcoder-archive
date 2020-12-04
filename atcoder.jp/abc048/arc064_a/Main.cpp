#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long int ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll Svec(vector<ll> v){
  ll n=0;
  for(ll i=0;i<v.size();i++) n+=v[i];
  return n;
}
int main(){
  IOS;
  ll n,x,ans;cin>>n>>x;
  vector<ll> v(n);
  rep(i,n) cin>>v[i];
  ans=Svec(v);
  if(v[0]>x) v[0]=x;
  rep(i,n-1){
    if(v[i]+v[i+1]>x){
      v[i+1]=x-v[i];
    }
  }
  cout<<ans-Svec(v)<<endl;
}