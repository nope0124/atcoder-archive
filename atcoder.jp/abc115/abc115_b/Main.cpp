#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
  int n,ans=0;
  cin>>n;
  vector<int> v(n);
  rep(i,n) cin>>v[i];
  sort(v.begin(),v.end());
  for(int i=0;i<n-1;i++){
    ans+=v[i];
  }
  ans+=v[n-1]/2;
  cout<<ans<<endl;
}
