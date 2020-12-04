#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,s=0;
  cin>>a>>b>>c>>x;
  for(int p=0;p<=a;p++){
    for(int q=0;q<=b;q++){
      for(int r=0;r<=c;r++){
        if(p*500+q*100+r*50==x){
          s++;
        }
      }
    }
  }
  cout<<s<<endl;
}
