#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for(ll i = 0; i < (n); i++)

bool palindrome(string s){
  bool flag=true;
  rep(i,s.size()) if(s[i]!=s[s.size()-1-i]) flag=false;
  return flag;
}

int main(){
  string s;cin>>s;
  ll n=s.size();
  string s1=s.substr(0,n/2),s2=s.substr(n/2+1,n/2);
  if(palindrome(s) && palindrome(s1) && palindrome(s2)) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}