#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
  string a,b;
  cin>>a>>b;
  for(int i=0;i<a.size();i++){
    a=a[a.size()-1]+a;
    a.pop_back();
    if(a==b){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}
