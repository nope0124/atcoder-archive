#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
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






int gcd(int a,int b)
{
 
  int r, tmp;
 
  
 
  /* 自然数 a > b を確認・入替 */
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
 
  /* ユークリッドの互除法 */
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
 
 
 
  return b;
}







int fac(int n){
  int m=1;
  while(n>=1) m*=n,n--;
  return m;
}

int vec_sum(vector<int> v){
  int n=0;
  for(int i=0;i<v.size();i++) n+=v[i];
  return n;
}
///////////////////////////
int main() {
  int n,m;
  bool flag=true,ans=false;
  cin>>n>>m;
  vector<string> v(n),w(m);
  rep(i,n) cin>>v[i];
  rep(i,m) cin>>w[i];
  for(int i=0;i<n-m+1;i++){
    for(int j=0;j<n-m+1;j++){
      flag=true;
      for(int k=0;k<m;k++){
        for(int l=0;l<m;l++){
          if(v[i+k][j+l]!=w[k][l]){
            flag=false;
            break;
          }
          
          
          
        }
      }
      if(flag){
        ans=true;
        break;
      }
      
      
      
      
    }
  }
  
  
  if(ans){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  
  
}
///////////////////////////



