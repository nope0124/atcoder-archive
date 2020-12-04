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
  int n;
  cin>>n;
  vector<int> v(n),a(n),b(n);
  rep(i,n) cin>>v[i]>>a[i]>>b[i];
  rep(i,n){
    if(v[i]%2!=(a[i]+b[i])%2){
      cout<<"No"<<endl;
      return 0;
    }
    if(abs(a[i])+abs(b[i])>v[i]){
      cout<<"No"<<endl;
      return 0;
    }
  }
  rep(i,n-1){
    if(abs(v[i+1]-v[i])<abs(a[i+1]-a[i])+abs(b[i+1]-b[i])){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  
  
  
}
///////////////////////////