/*Function Template*/
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define rep(i, n) for(long long int i = 0; i < (n); i++)


int Len(int n) {
  int s=0;
  while(n!=0) s++, n/=10;
  return s;
}


int Sint(int n) {
  int m=0,s=0,a=n;
  while(a!=0) s++, a/=10;
  for(int i=s-1;i>=0;i--) m+=n/((int)pow(10,i))-(n/((int)pow(10,i+1)))*10;
  return m;
}


long long int Svec(vector<long long int> v){
  long long int n=0;
  for(long long int i=0;i<v.size();i++) n+=v[i];
  return n;
}


int GCD(int a,int b){
  int r,tmp;
/*自然数 a > b を確認・入替*/
  if(a<b){
    tmp=a,a=b,b=tmp;
  }
/*ユークリッドの互除法*/
  r=a%b;
  while(r!=0){
    a=b,b=r,r=a%b;
  }
  return b;
}


int LCM(int a,int b){
  int c=a,d=b,r,tmp;
/*自然数 a > b を確認・入替*/
  if(a<b){
    tmp=a,a=b,b=tmp;
  }
/*ユークリッドの互除法*/
  r=a%b;
  while(r!=0){
    a=b,b=r,r=a%b;
  }
  return c/b*d;
}


int Factorial(int n){
  int m=1;
  while(n>=1) m*=n,n--;
  return m;
}


/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  long long int n,k;
  cin>>k>>n;
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  vector<long long int> v(n),w(n-1);
  rep(i,n) cin>>v[i];
  
  sort(v.begin(),v.end());
  rep(i,n-1){
    w[i]=v[i+1]-v[i];
  }
  sort(w.begin(),w.end(),greater<int>());
  long long int ans=Svec(w);
  if(k==1){
    cout<<ans<<endl;
    return 0;
  }
  if(k-1>=w.size()){
    cout<<0<<endl;
    return 0;
  }
  rep(i,k-1){
    ans-=w[i];
  }
  cout<<ans<<endl;
}

