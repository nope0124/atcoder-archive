#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
  int n,ans=0;
  cin>>n;
  vector<int> a(n),b(n);
  rep(i,n) cin>>a[i];
  rep(i,n) cin>>b[i];
  rep(i,n){
    if(a[i]>b[i]){
      ans+=a[i]-b[i];
    }
  }
  cout<<ans<<endl;
}
