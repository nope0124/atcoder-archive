#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,a=0,b=0;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  sort(v.begin(),v.end());
  if(v.size()%2==0){
    for(int i=1;i<=n/2;i++){
      a+=v[2*i-2];
      b+=v[2*i-1];
    }
  }else{
    for(int i=1;i<=n/2;i++){
      a+=v[2*i-1];
    }
    for(int i=1;i<=(n+1)/2;i++){
      b+=v[2*i-2];
    }
  }
  cout<<abs(a-b)<<endl;
}
