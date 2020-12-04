/*Function Template*/
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define rep(i, n) for(int i = 0; i < (n); i++)


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


int Svec(vector<int> v){
  int n=0;
  for(int i=0;i<v.size();i++) n+=v[i];
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
  long long int n,m;
  cin>>n>>m;
  cout<<(m*1900+(n-m)*100)*(long long int)pow(2,m)<<endl;
}