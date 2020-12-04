#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a=0;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  for(int i=0;i<30;i++){
    for(int j=0;j<n;j++){
      if(v[j]%2==0){
        
      }else{
        cout<<i<<endl;
        return 0;
      }
      v[j]/=2;
      
    }
  }
}
