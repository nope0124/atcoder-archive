#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
  bool w=false,e=false,n=false,s=false;
  string a;
  cin>>a;
  rep(i,a.size()){
    if(a[i]=='W'){
      w=true;
    }
    if(a[i]=='E'){
      e=true;
    }
    if(a[i]=='N'){
      n=true;
    }
    if(a[i]=='S'){
      s=true;
    }
  }
  if(!(w^e) && !(n^s)){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
