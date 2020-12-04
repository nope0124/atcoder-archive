#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,s,t,w,sum;
    cin >>n>>s>>t>>w;
    if(s<=w && w<=t){
      sum++;
    }
     for (int i = 0; i < n-1; i++)
    {
        int dif; cin >> dif;
        w += dif;
        if (s<=w && w<=t) sum++;
    }
    cout<<sum<<endl;
}
