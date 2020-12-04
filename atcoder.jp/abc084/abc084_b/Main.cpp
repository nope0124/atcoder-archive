#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  string s;
  cin>>a>>b>>s;
  for(int i=0;i<s.size();i++){
    
    if(s[i]=='-' && i!=a){
      cout<<"No"<<endl;
      return 0;
    }
  }
  if(a+b+1==s.size() && s[a]=='-'){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  
}
