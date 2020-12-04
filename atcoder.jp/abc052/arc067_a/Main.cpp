#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  map<int,int> mp;
  for(int i=2;i<=n;i++){
    int j=2,k=i;
    while(k>1){
      if(k%j==0){
        k/=j;mp[j]++;
      }else{
        j++;
      }
    }
  }
  long ans=1;
  for(auto c:mp){
    ans*=(c.second+1);
    ans%=1000000007;
  }
  cout<<ans<<endl;
}