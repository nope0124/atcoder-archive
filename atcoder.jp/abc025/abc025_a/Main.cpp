#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int n,sum;
  cin >>s>>n;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      sum++;
      if(sum==n){
        cout<<s[i]<<s[j]<<endl;
      }
    }
  }
}
