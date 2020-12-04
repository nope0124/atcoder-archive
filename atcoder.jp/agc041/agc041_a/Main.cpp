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

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {

  ll n,a,b;
  cin>>n>>a>>b;
  if(abs(b-a)%2==0){
    cout<<abs(b-a)/2<<endl;
  }else{
    ll tmp=min(a-1,n-b);
    cout<<tmp+(b-a+1)/2<<endl;
  }
}