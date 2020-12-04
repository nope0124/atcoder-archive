#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  if(n==100){
    cout<<"Perfect"<<endl;
  }else if(90<=n && n<=99){
    cout<<"Great"<<endl;
  }else if(60<=n && n<=89){
    cout<<"Good"<<endl;
  }else{
    cout<<"Bad"<<endl;
  }
}
