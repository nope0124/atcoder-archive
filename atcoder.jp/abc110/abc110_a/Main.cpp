#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  vector<int> v={a,b,c};
  sort(v.begin(),v.end());
  cout<<v[2]*10+v[1]+v[0]<<endl;
}
