#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

int int_len(int n) {
  int s=0;
  while(n!=0) s++, n/=10;
  return s;
}

int int_sum(int n) {
  int m=0,s=0,a=n;
  while(a!=0) s++, a/=10;
  for(int i=s-1;i>=0;i--) m+=n/((int)pow(10,i))-(n/((int)pow(10,i+1)))*10;
  return m;
}


int vec_sum(vector<int> v){
  int n=0;
  for(int i=0;i<v.size();i++) n+=v[i];
  return n;
}

int main() {
  long long int n,ans=0;
  cin>>n;
  vector<int> v(3*n);
  rep(i,3*n) cin>>v[i];
  sort(v.begin(),v.end());
  for(int i=0;i<n;i++){
    ans+=v[3*n-2*(i+1)];
  }
  
  cout<<ans<<endl;
  
  
  
}
