/*Function Template*/
#include<bits/stdc++.h>
using namespace std;



/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
int main() {
  int n;
  bool flag=false;
  cin>>n;
  for(int i=1;i<=9;i++){
    int a;
    if(n%i==0){
      a=n/i;
      if(i<=9 && a<=9){
        flag=true;
        break;
      }
    }
  }
  if(flag){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}