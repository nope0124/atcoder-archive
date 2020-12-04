#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1000000007;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
  IOS;
  ll n,k;
  cin>>n>>k;
  ll ans=0;
  for(ll i=k+1;i<=n;i++){
    ans+=(i-k)*(n/i);
    ll r=n%i;
    if(r!=0 && r>=k){
      ans+=r-max((ll)0,k-1);
    }
  }
  cout<<ans<<endl;
}

