#include <bits/stdc++.h>
using namespace std;
int main(){
  char s;
  vector<char> v{'a','i','u','e','o'};
  cin>>s;
  for(int i=0;i<5;i++){
    if(s==v.at(i)){
      cout<<"vowel"<<endl;
      return 0;
    }
  }
  cout<<"consonant"<<endl;
}
