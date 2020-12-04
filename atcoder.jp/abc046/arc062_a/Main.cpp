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






int ggcd(int a,int b)
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
  long long int n,k;
  cin>>n;
  vector<long long int> a(n),b(n),c(n),d(n);
  rep(i,n) cin>>a[i]>>b[i];
  c[0]=a[0];
  d[0]=b[0];
  rep(i,n-1){
    k=max((c[i]+a[i+1]-1)/a[i+1],(d[i]+b[i+1]-1)/b[i+1]);
    c[i+1]=k*a[i+1];
    d[i+1]=k*b[i+1];
  }
  cout<<c[n-1]+d[n-1]<<endl;
}
///////////////////////////