#include<bits/stdc++.h>
using namespace std;
int main(){
  int l_1,l_2,l_3;
  cin>>l_1>>l_2>>l_3;
  if(l_1==l_2){
    cout<<l_3<<endl;
  }else if(l_2==l_3){
    cout<<l_1<<endl;
  }else{
    cout<<l_2<<endl;
  }
}