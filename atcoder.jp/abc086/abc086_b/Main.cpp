#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c=0,d;
  cin>>a>>b;
  d=b;
  while(d!=0){
    d/=10;
    c++;
  }
  for(int i=0;i<c;i++){
    a*=10;
  }
  a=a+b;
  if(ceil(sqrt(a))*ceil(sqrt(a))==a){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
