#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define ALL(a)  (a).begin(),(a).end()
int main() {
  ll n;cin>>n;
  vector<ll> v(n),ans(n,1e6);
  rep(i,n) cin>>v[i];
  rep(i,n) ans[lower_bound(ALL(ans),v[i])-ans.begin()]=min(ans[lower_bound(ALL(ans),v[i])-ans.begin()],v[i]);
  cout<<n-(lower_bound(ALL(ans),1e6)-ans.begin())<<endl;
}