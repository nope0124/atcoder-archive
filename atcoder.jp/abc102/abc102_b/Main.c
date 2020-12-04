#include <stdio.h>
int main(){
    // Your code here!
    int n;
    scanf("%d",&n);
    int a=1000000000;
    int b=0;
    for(int i=0;i<n;i++){
        int tmp;scanf("%d",&tmp);
        if(tmp<a) a=tmp;
        if(tmp>b) b=tmp;
    }
    printf("%d",b-a);
}
