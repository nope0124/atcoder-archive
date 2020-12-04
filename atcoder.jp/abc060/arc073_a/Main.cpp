#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

int int_len(long long int n) {
  int s=0;
  while(n!=0) s++, n/=10;
  return s;
}

int int_sum(long long int n) {
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
///////////////////////////
int main() {
  long long int a=0,b=0,c=0,d=0,n=0,count=0,ans=1000000;
  string s;
  cin>>n>>a;
  vector<int> t(n);
  rep(i,n) cin>>t[i];
  ans=t[0];
  rep(i,n-1){
    if(a>=t[i+1]-t[i]) ans+=t[i+1]-t[i];
    else ans+=a;
  }
  ans+=a;
  cout<<ans<<endl;
}
///////////////////////////



