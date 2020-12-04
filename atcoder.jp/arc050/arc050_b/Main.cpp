#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll r,b,x,y;
bool ok(ll n){
  if(r-n>=0 && b-n>=0 && ((r-n)/(x-1)+(b-n)/(y-1))>=n) return true;
  return false;
}

int main() {
  cin>>r>>b>>x>>y;
  ll ans=0;
  for(ll i=62;i>=0;i--) if(ok(ans+(1LL<<i))) ans+=1LL<<i;
  cout<<ans<<endl;
}