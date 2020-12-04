#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
  long long int a,b,c,n;
  cin>>a>>b>>c;
  if(a%2==0 || b%2==0 || c%2==0){
    cout<<0<<endl;
    return 0;
  }
  n=min(a*b,min(b*c,c*a));
  cout<<n<<endl;
}
