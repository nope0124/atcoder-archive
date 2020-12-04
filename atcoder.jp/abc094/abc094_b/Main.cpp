#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
int main(){
  int n,m,x,p=0,q=0;
  cin>>n>>m>>x;
  vector<int> v(n),a(m);
  rep(i,n) v[i]=0;
  rep(i,m){
    cin>>a[i];
    v[a[i]-1]=1;
  }
  for(int i=0;i<x;i++){
    if(v[i]==1) p++;
  }
  for(int i=x;i<=n;i++){
    if(v[i]==1) q++;
  }
  cout<<min(p,q)<<endl;
}
