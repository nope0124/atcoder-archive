#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> gr={0,2,0,1,0,1,0,0,1,0,1,0};
  int x,y;
  cin>>x>>y;
  if(gr[x-1]==gr[y-1])
    cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
