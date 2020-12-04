#include <bits/stdc++.h>
using namespace std;
int main(){
  int k;
  cin>>k;
  if(k%2==0){
    cout<<k*k/4<<endl;
  }else{
    cout<<(k/2)*((k+1)/2)<<endl;
  }
}
