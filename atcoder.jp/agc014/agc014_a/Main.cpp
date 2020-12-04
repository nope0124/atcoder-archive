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
  int x,a,b,c,ans=0;
  vector<int> n(3);
  rep(i,3) cin>>n[i];
  if(n[0]==n[1] && n[1]==n[2]){
    if(n[0]%2==0){
      cout<<-1<<endl;
      return 0;
    }else if(n[0]%2!=0){
      cout<<0<<endl;
      return 0;
    }
  }
  sort(n.begin(),n.end());
  
  x=n[2]-n[0];
  
  while(x%2==0){
    x/=2;
    if((n[0]+n[1])%2==0 && (n[0]+n[2])%2==0 && (n[1]+n[2])%2==0){
      a=(n[0]+n[1])/2;
      b=(n[0]+n[2])/2;
      c=(n[1]+n[2])/2;
      n[0]=a;
      n[1]=b;
      n[2]=c;
      ans++;
    }else{
      cout<<ans<<endl;
      return 0;
    }    
  }
  cout<<ans<<endl;
  
}
