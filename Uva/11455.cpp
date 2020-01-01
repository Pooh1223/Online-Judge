#include <bits/stdc++.h>
using namespace std;

bool isRect(long long a,long long b,long long c,long long d){
    if(a == b && c == d){
        return 1;
    } else if(a == c && b == d){
        return 1;
    } else if(a == d && b == c){
        return 1;
    } else {
        return 0;
    }
}

bool isQuad(long long a,long long b,long long c,long long d){
    long long inf[10], sup[10];

    sup[0] = a + b - 1;
    sup[1] = a + c - 1;
    sup[2] = a + d - 1;
    sup[3] = c + d - 1;
    sup[4] = b + d - 1;
    sup[5] = b + c - 1;

    inf[0] = abs(a - b) + 1;
    inf[1] = abs(a - c) + 1;
    inf[2] = abs(a - d) + 1;
    inf[3] = abs(c - d) + 1;
    inf[4] = abs(b - d) + 1;
    inf[5] = abs(b - c) + 1;

    if((sup[0] < inf[3] || sup[3] < inf[0])){
        if((sup[1] < inf[4] || sup[4] < inf[1])){
            if((sup[2] < inf[5] || sup[5] < inf[2])){
                return 0;
            }
        }
    }

    return 1;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        long long a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a == b && b == c && c == d){
            cout << "square\n";
        } else if(isRect(a,b,c,d)){
            cout << "rectangle\n";
        } else if(isQuad(a,b,c,d)){
            cout << "quadrangle\n";
        } else {
            cout << "banana\n";
        }
    }

    return 0;
}
