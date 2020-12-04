#include<cstdio>
using namespace std;
int main(){
	int y,m,d;
	scanf("%d/%d/%d",&y,&m,&d);
	while(y%(m*d)!=0){
		d++;
		if(d>31||((m==4||m==6||m==9||m==11)&&d>30)||(m==2&&d>29)||(m==2&&d>28&&(y%4||(y%100==0&&y%400)))){
			m++;
			d=1;
		}
		if(m==13){
			y++;
			m=1;
		}
	}
	printf("%04d/%02d/%02d\n",y,m,d);
}