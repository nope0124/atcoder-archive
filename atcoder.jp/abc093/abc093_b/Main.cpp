#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
int main(){
  int a,b,k;
  cin>>a>>b>>k;
  vector<int> v;
  if(k*2>=b-a+1){
    for(int i=a;i<=b;i++) cout<<i<<endl;
    return 0;
  }
  rep(i,k){
    v.push_back(a+i);
    v.push_back(b-i);
  }
  sort(v.begin(),v.end());
  rep(i,v.size()) cout<<v[i]<<endl;
}
