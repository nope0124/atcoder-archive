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
  int n,cnt=0;
  int flag=0;
  cin>>n;
  vector<int> v;
  v.push_back(n);
  while(true){
    if(n==1){
      flag++;
    }
    if(n%2==0){
      n/=2;
      v.push_back(n);
    }else{
      n*=3;
      n++;
      v.push_back(n);
    }
    if(flag>=2){
      break;
    }
  }
  
  
  
  
  
  for(int i=0;i<v.size()-1;i++){
    for(int j=i+1;j<v.size();j++){
      if(v[i]==v[j]){
        cout<<max(i,j)+1<<endl;
        return 0;
      }
    }
  }
  
  
  
}
///////////////////////////