#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define rep(i, n) for(int i = 0; i < (n); i++)

///////////////////////////
int main() {
  string s;
  cin>>s;
  long long int k,ans=0,aans=0,p=0,str,count=0;
  bool flag=true;
  cin>>k;
  vector<string> v;
  
  for(long long int i=0;i<s.size();i++){
    
    if(flag){
      str=i;
      flag=false;
    }
    
    if(s[i]==s[i+1]){
      count++;
    }else{
      flag=1;
      v.push_back(s.substr(str,count+1));
      count=0;
      flag=true;
    }
    
  }
  
  if(v.size()!=1){
    
    if(s[0]==s[s.size()-1]){

      p+=v[0].size()/2+v[v.size()-1].size()/2;
      for(int i=1;i<v.size()-1;i++){
        ans+=v[i].size()/2;
      }
      aans+=(v[0].size()+v[v.size()-1].size())/2;
      cout<<ans*k+aans*(k-1)+p<<endl;

    }else{

      for(long long int i=0;i<v.size();i++){
        ans+=v[i].size()/2;
      }


      cout<<ans*k<<endl;

    }
    
  }else{
    cout<<s.size()*k/2<<endl;
  }
  
  
  
  
}
///////////////////////////