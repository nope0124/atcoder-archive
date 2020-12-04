#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
  int n,t,s=0;
  cin>>n>>t;
  vector<int> a(n),b(n);
  rep(i,n) cin>>a[i]>>b[i];
  rep(i,n){
    if(b[i]>t){
      a[i]=1000;
      s++;
    }
  }
  sort(a.begin(),a.end());
  if(s!=n){
  cout<<a[0]<<endl;
  }else{
    cout<<"TLE"<<endl;
  }
}
