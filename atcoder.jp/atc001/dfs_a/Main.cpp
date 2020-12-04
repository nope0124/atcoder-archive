#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
ll dx[4]={-1,1,0,0};
ll dy[4]={0,0,-1,1};
bool reached[500][500];
ll h,w;
char v[500][500];
void solve(ll x,ll y){
  if(v[y][x]=='#') return;
  if(reached[y][x]) return;
  if(x<0 || w<=x || y<0 || h<=y) return;
  reached[y][x]=true;
  rep(i,4) solve(x+dx[i],y+dy[i]);
}
int main(){
  cin>>h>>w;
  ll sx,sy,gx,gy;
  rep(i,h){
    rep(j,w){
      cin>>v[i][j];
    }
  }
  rep(i,h){
    rep(j,w){
      if(v[i][j]=='s'){
        sx=j;
        sy=i;
      }
      if(v[i][j]=='g'){
        gx=j;
        gy=i;
      }
      reached[i][j]=false;
    }
  }
  solve(sx,sy);
  if(reached[gy][gx]) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}