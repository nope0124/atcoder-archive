#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int N,K,T[5][5];
bool dfs(int n,int value){
  if(n==N) return (value==0);
  rep(i,K) if(dfs(n+1,value^T[n][i])) return true;
  return false;
}
int main(){
  cin>>N>>K;
  rep(i,N) rep(j,K) cin>>T[i][j];
  if(dfs(0,0)) cout<<"Found"<<endl;
  else cout<<"Nothing"<<endl;
}