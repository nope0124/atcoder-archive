#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(abs(a-b)<=d && abs(b-c)<=d || abs(a-c)<=d){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
