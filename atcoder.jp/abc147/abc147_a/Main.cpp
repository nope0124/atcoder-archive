/*Function Template*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 510000;
const int MOD = 1000000007;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define ALL(a)  (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll fac[MAX], finv[MAX], inv[MAX];


int main() {
  IOS;
  ll a,b,c;
  cin>>a>>b>>c;
  if(a+b+c>=22){
    cout<<"bust"<<endl;
  }else{
    cout<<"win"<<endl;
  }
}