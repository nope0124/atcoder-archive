#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
int main(){
  int n;cin>>n;
  vector<int> v(n),a(n,1e9+1);
  rep(i,n) cin>>v[i];
  reverse(ALL(v));
  rep(i,n) a[upper_bound(ALL(a),v[i])-a.begin()]=v[i];
  cout<<lower_bound(ALL(a),1e9+1)-a.begin()<<endl;
}