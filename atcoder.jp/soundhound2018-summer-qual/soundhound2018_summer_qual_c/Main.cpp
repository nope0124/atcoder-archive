#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
  ll n,m,d;
  cin>>n>>m>>d;
  cout<<setprecision(10);
  if(d==0) cout<<(m-1)*(double)1/n<<endl;
  else cout<<(m-1)*(double)2*(n-d)/(n*n)<<endl;
}