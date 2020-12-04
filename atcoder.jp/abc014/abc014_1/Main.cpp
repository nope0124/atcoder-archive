#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >>a;
  cin >>b;
  if(a%b!=0){
    cout<<b-(a%b)<<endl;
  }else{
    cout<<0<<endl;
  }
}