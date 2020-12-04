#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[3];
    for(int i = 0; i < 3; i++){
      cin >> a[i];
    }
    for(int i = 0; i < 3; i++){
        int cnt = 0;
        for(int j = 0; j < 3; j++){
          if(i == j){
            continue;
          }
          if(a[i] < a[j]){
            cnt++;
          }
        }
        cout << cnt + 1 << endl;
    }
}