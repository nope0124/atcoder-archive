#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,q;
  cin>>n>>k>>q;
  vector<int> v(n),b(q);
  for(int i=0;i<n;i++) v[i]=k;
  for(int i=0;i<q;i++) cin>>b[i];
  for(int i=0;i<q;i++){
    v[b[i]-1]+=1;
  }
  
  for(int i=0;i<n;i++){
    if(v[i]<=q){
      cout<<"No"<<endl;
    }else{
      cout<<"Yes"<<endl;
    }
  }
  
}