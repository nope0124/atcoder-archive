#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
int main(){
  ll n,m,ans=0;cin>>n>>m;
  priority_queue<ll> p;
  rep(i,n){
    ll a;
    cin>>a;
    p.push(a);
  }
  rep(i,m){
    ll b=p.top();
    p.pop();
    p.push(b/2);
  }
  rep(i,n){
    ans+=p.top();
    p.pop();
  }
  cout<<ans<<endl;
}