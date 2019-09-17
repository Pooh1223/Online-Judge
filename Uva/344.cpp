#include <bits/stdc++.h>
using namespace std;

int nm[5][103];

void forten(int u,int id){
    if(u == 4){
        nm[2][id] += 1;
        nm[3][id] += 1;
    } else if(u == 9){
        nm[2][id] += 1;
        nm[4][id] += 1;
    } else {
        if(u < 5){
            nm[2][id] += u;
        } else if(u == 5){
            nm[3][id] += 1;
        } else {
            nm[2][id] += u - 5;
            nm[3][id] += 1;
        }
    }
}

void fordig(int u,int id){
    if(u == 4){
        nm[0][id] += 1;
        nm[1][id] += 1;
    } else if(u == 9){
        nm[0][id] += 1;
        nm[2][id] += 1;
    } else {
        if(u < 5){
            nm[0][id] += u;
        } else if(u == 5){
            nm[1][id] += 1;
        } else {
            nm[0][id] += u - 5;
            nm[1][id] += 1;
        }
    }
}

int main(){
    nm[0][1] = 1;
    for(int i = 2;i <= 100;++i){
        int a = i / 10,b = i % 10;

        for(int j = 0;j < 5;++j) nm[j][i] += nm[j][i - 1];
        
        forten(a,i);
        fordig(b,i);
    }
    int n;
    while(cin >> n && n){
        cout << n << ": " << nm[0][n] << " i, " << nm[1][n] << " v, " << nm[2][n] << " x, " << nm[3][n] << " l, " << nm[4][n] << " c\n";
    }
    return 0;
}
