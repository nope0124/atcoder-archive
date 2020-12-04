#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b=0,c;
  cin>>a;
  c=a;
  while(a!=0){
    b+=a%10;
    a/=10;
  }
  if(c%b==0){
    cout<<"Yes"<<endl;
    
  }else{
    cout<<"No"<<endl;
  }
}
