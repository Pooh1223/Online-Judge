#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    while(~scanf("%d %d",&a,&b)){
        printf("%10d%10d    ",a,b);
        if(__gcd(a,b) == 1){
            printf("Good Choice\n\n");
        } else {
            printf("Bad Choice\n\n");
        }
    }
    return 0;
}
