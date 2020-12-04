#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
  int a;
  cin>>a;
  rep(i,a/4+1){
    rep(j,a/4+1){
      if(i*4+j*7==a){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
}
