#include <bits/stdc++.h>
using namespace std;

bool snm[1000003];

int nextnm(int nm){
    int sum = nm;

    while(nm){
        sum += nm % 10;
        nm /= 10;
    }

    return sum;
}

int main(){
    for(int i = 2;i <= 1000000;++i){
        int pos = i;
        
        if(i == 2){
            while(pos <= 1000000 && !snm[pos]){
                snm[pos] = 1;
                pos = nextnm(pos);
            }
        } else {
            do{
                if(pos != i) snm[pos] = 1;
                pos = nextnm(pos);
            }while(pos <= 1000000 && !snm[pos]);
        }
        
    }

    for(int i = 1;i <= 1000000;++i){
        if(!snm[i]) cout << i << "\n";
    }
    return 0;
}
