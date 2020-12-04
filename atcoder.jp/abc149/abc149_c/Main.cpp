/*Function Template*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 510000;
const int MOD = 1000000007;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define ALL(a)  (a).begin(),(a).end()



const int MAX_N=100010;
vector<bool> sss(){
  vector<bool> isPrime(MAX_N+1,true);
  for(int i=2;i<=MAX_N;i++){
    if(isPrime[i]){
      for(int j=2*i;j<=MAX_N;j+=i){
        isPrime[j]=false;
      }
    }
  }
  return isPrime;
}



/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  ll n;
  cin>>n;
  vector<bool> p=sss();
 
  while(!p[n]){
    n++;
  }
  cout<<n<<endl;
}
