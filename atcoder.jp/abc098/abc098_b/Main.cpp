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
  int n,ans=0,count=0;
  string s;
  cin>>n>>s;
  for(int i=1;i<n;i++){
  set<char> st1,st2;
  for(int j=0;j<i;j++) st1.insert(s[j]);
  for(int j=i;j<n;j++) st2.insert(s[j]);
  for(int j : st1) for(int k : st2) if(j==k) count++;
  ans=max(ans,count);
  count=0;
  }
  cout<<ans<<endl;
}
