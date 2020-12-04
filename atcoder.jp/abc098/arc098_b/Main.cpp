#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
int main(){
  ll n;
  cin>>n;
  vector<ll> v(n);
  rep(i,n) cin>>v[i];
  ll ans=0;
  ll right=0;
  ll sum=0;
  rep(left,n){
    while(right<n && (sum^v[right])==(sum+v[right])){
      sum+=v[right];
      right++;
    }
    ans+=right-left;
    if(left==right) right++;
    else sum-=v[left];
  }
  cout<<ans<<endl;
}