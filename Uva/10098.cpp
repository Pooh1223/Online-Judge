#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char str[13];
        scanf("%s",&str);
        int len = strlen(str);
        sort(str,str + len);
        do{
            printf("%s\n",str);
        }while(next_permutation(str,str + len));
        printf("\n");
    }
    return 0;  
}
