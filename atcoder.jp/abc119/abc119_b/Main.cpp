#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
  int n;
  double ans=0;
  cin>>n;
  vector<double> a(n);
  vector<string> b(n);
  rep(i,n) cin>>a[i]>>b[i];
  rep(i,n){
    if(b[i]=="JPY"){
      ans+=a[i];
    }else{
      ans+=a[i]*380000;
    }
  }
  cout<<ans<<endl;
}
