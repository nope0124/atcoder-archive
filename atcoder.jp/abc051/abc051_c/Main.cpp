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
///////////////////////////
int main() {
  long long int a=0,b=0,c=0,d=0,n=0,h,w,count=0,ans=0;
  string s;
  cin>>a>>b>>c>>d;
  h=d-b;
  w=c-a;
  rep(i,w) cout<<'R';
  rep(i,h) cout<<'U';
  rep(i,w) cout<<'L';
  rep(i,h) cout<<'D';
  cout<<'D';
  rep(i,w+1) cout<<'R';
  rep(i,h+1) cout<<'U';
  cout<<'L'<<'U';
  rep(i,w+1) cout<<'L';
  rep(i,h+1) cout<<'D';
  cout<<'R'<<endl;
  
  
  
}
///////////////////////////