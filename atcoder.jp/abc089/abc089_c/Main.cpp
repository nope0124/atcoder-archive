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
  int n;
  cin>>n;
  vector<long long int> c(5);
  rep(i,5) c[i]=0;
  rep(i,n){
    string s;
    cin>>s;
    if(s[0]=='M'){
      c[0]++;
    }else if(s[0]=='A'){
      c[1]++;
    }else if(s[0]=='R'){
      c[2]++;
    }else if(s[0]=='C'){
      c[3]++;
    }else if(s[0]=='H'){
      c[4]++;
    }
  }
  
    long long int ans=0;
    for(int i=0;i<3;i++){
      for(int j=i+1;j<4;j++){
        for(int k=j+1;k<5;k++){
          ans+=c[i]*c[j]*c[k];
        }
      }
    }
  cout<<ans<<endl;
}
