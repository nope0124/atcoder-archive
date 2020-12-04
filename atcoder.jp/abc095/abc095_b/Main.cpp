#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
int main(){
  int n,x,ans,s=0;
  cin>>n>>x;
  ans=n;
  vector<int> v(n);
  rep(i,n) cin>>v[i], s+=v[i];
  s=x-s;
  sort(v.begin(),v.end());
  cout<<ans+s/v[0]<<endl;
}
