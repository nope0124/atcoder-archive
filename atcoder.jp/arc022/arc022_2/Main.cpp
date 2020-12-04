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
  set<ll> member;
  rep(left,n){
    while(right<n && !member.count(v[right])){
      member.insert(v[right]);
      right++;
    }
    ans=max(ans,right-left);
    if(left==right) right++;
    else member.erase(v[left]);
  }
  cout<<ans<<endl;
}