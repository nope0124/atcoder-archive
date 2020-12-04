#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c=0;
  cin>>a>>b;
  for(int i=a;i<=b;i++){
    if(i/10000==i-(i/10)*10 && i/1000-(i/10000)*10==i/10-(i/100)*10){
      c++;
    }
  }
  cout<<c<<endl;
}
