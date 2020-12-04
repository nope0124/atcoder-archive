#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main(){
  double n,ans=0;
  cin>>n;
  vector<double> a(n),b(n),v;
  rep(i,n) cin>>a[i]>>b[i];
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      ans=max(ans,pow((a[i]-a[j]),2)+pow((b[i]-b[j]),2));
    }
  }
  cout<<setprecision(9)<<sqrt(ans)<<endl;
}