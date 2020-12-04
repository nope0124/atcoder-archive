#include<bits/stdc++.h>
using namespace std;
int main(){
  int a=0;
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(i%2==0){
      if(s[i]=='R' || s[i]=='U' || s[i]=='D'){
        a+=1;
      }
    }else{
      if(s[i]=='L' || s[i]=='U' || s[i]=='D'){
        a+=1;
      }
    }
  }
  if(a==s.size()){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}