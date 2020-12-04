#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)




int main() {
  int h,w,a,b,x,t;
  cin>>h>>w>>a>>b;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if((j<a)^(i<b)){
        cout<<'0';
      }else{
        cout<<'1';
      }
    }
    cout<<endl;
  }
}