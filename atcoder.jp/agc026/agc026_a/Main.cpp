#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define rep(i, n) for(int i = 0; i < (n); i++)

///////////////////////////
int main() {
  int n,ans=0,k=0;
  cin>>n;
  vector<int> v(n),a(n);
  rep(i,n) a[i]=1;
  rep(i,n) cin>>v[i];
  rep(i,n-1){
    
    if(v[i]==v[i+1]){
      a[k]++;
    }else{
      k++;
    }
    
  }
  rep(i,n){
    ans+=a[i]/2;
    
  }
  
  cout<<ans<<endl;
  
}
///////////////////////////

