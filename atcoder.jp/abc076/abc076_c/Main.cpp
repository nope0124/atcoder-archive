#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main(){
  vector<string> v;
  string s,t;
  cin>>s>>t;
  rep(i,s.size()-t.size()+1){
    string tmp=s.substr(i,t.size());
    bool flag=true;
    rep(j,t.size()) if(!(t[j]==tmp[j] || tmp[j]=='?')) flag=false;
    if(flag){
      string ans=s.substr(0,i)+t+s.substr(i+t.size());
      rep(j,ans.size()) if(ans[j]=='?') ans[j]='a';
      v.push_back(ans);
    }
  }
  if(v.size()!=0){
    sort(v.begin(),v.end());
    cout<<v[0]<<endl;
  }else{
    cout<<"UNRESTORABLE"<<endl;
  }
}