#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

char maze[10][10];
bool reached[10][10];
ll dx[4]={-1,1,0,0};
ll dy[4]={0,0,-1,1};

void search(ll y,ll x){
  if(reached[y][x]) return;
  if(x<0 || 10<=x || y<0 || 10<=y) return;
  if(maze[y][x]=='x') return;
  reached[y][x]=true;
  rep(i,4) search(y+dy[i],x+dx[i]);
}

int main(){
  ll cnt=1;
  
  rep(i,10){
    rep(j,10){
      cin>>maze[i][j];
      if(maze[i][j]=='o') cnt++;
    }
  }
  
  rep(i,10){
    rep(j,10){
      ll ans=0;
      rep(k,10) rep(l,10) reached[k][l]=false;
      if(maze[i][j]=='o') continue;
      maze[i][j]='o';
      search(i,j);
      rep(k,10) rep(l,10) if(reached[k][l]) ans++;
      if(ans==cnt){
        cout<<"YES"<<endl;
        return 0;
      }
      maze[i][j]='x';
    }
  }
  
  cout<<"NO"<<endl;
}