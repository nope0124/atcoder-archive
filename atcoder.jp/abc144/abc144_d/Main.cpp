#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

ll mod = 1e9 + 7;

int main(){
	double a,b,x;
	cin >> a >> b >> x;
	
	if(x/a < a*b/2){
		double l = 2*(x/a)/b;
		double t = atan2(b,l)*180/M_PI;
		printf("%.10lf\n",t);
	}else{
		double x2 = a*b-(x/a);
		double l = 2*(x2)/a;
		double t = atan2(l,a)*180/M_PI;
		printf("%.10lf\n",t);
	}

	return 0;
}
