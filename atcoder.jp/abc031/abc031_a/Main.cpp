#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,d;
  cin>>a>>d;
  if(a>=d){
    cout<<a*(d+1)<<endl;
  }else{
    cout<<(a+1)*d<<endl;
  }
}
