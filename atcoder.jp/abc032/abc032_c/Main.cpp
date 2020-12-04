#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
int main(){
  ll n,k;cin>>n>>k;
  vector<ll> v(n);
  rep(i,n){
    cin>>v[i];
    if(v[i]==0){
      cout<<n<<endl;
      return 0;
    }
  }
  ll ans=0;
  ll sum=1;
  ll right=0;
  rep(left,n){
    while(right<n && sum*v[right]<=k){
      sum*=v[right];
      right++;
    }
    ans=max(ans,right-left);
    if(left==right) right++;
    else sum/=v[left];
  }
  cout<<ans<<endl;
}