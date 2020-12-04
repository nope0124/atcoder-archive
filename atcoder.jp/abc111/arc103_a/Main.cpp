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
  long long int n,max1=0,max2=0,max3=0,max4=0,ans1=0,ans2=0,ans3=0,ans4=0,x,y;
  bool flag1=false,flag2=false;
  cin>>n;
  vector<long long int> a(n/2),b(n/2);
  unordered_map<long long int,long long int> mp1,mp2;
  rep(i,n){
    int m;
    cin>>m;
    if(i%2==0){
      a[i/2]=m;
    }else{
      b[i/2]=m;
    }
  }
  rep(i,n/2){
    mp1[a[i]]++;
    mp2[b[i]]++;
    
  }
  
  rep(i,n/2){
    if(max1<mp1[a[i]]){
      ans1=a[i];
      max1=mp1[a[i]];
    }
  }
  rep(i,n/2){
    if(max2<mp2[b[i]]){
      ans2=b[i];
      max2=mp2[b[i]];
    }
  }
  x=mp1[ans1];
  y=mp2[ans2];
  mp1[ans1]=0;
  mp2[ans2]=0;
  max1=0;
  max2=0;
  rep(i,n/2){
    if(max1<mp1[a[i]]){
      ans3=a[i];
      max1=mp1[a[i]];
    }
  }
  rep(i,n/2){
    if(max2<mp2[b[i]]){
      ans4=b[i];
      max2=mp2[b[i]];
    }
  }
  if(ans1!=ans2){
    cout<<n-x-y<<endl;
  }else{  
    cout<<min(n-x-mp2[ans4],n-y-mp1[ans3])<<endl;
  }
  
  
  
}
///////////////////////////



