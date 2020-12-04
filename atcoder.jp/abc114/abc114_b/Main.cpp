#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
  string s;
  int ans=753,a;
  cin>>s;
  rep(i,s.size()-2){
    a=100*(int)s[i]+10*(int)s[i+1]+(int)s[i+2]-5328;
    ans=min(abs(753-a),ans);
  }
  cout<<ans<<endl;
}
