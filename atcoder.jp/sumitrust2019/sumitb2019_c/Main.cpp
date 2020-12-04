#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=1;i<=(n);i++)
int main(){
  ll n;cin>>n;
  bool flag=false;
  rep(i,20) if(100*i<=n && n<=105*i) flag=true;
  if(n>=2100) flag=true;
  if(flag) cout<<1<<endl;
  else cout<<0<<endl;
}