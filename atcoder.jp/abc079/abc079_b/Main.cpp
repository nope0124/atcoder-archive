#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int n,a=2,b=1,c=3,d;
  cin>>n;
  for(int i=0;i<n;i++){
    c=c+b;
    d=b;
    b=b+a;
    a=d;
  }
  cout<<a<<endl;
}