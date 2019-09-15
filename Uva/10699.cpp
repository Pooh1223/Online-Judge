#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

int main(){
    prime.push_back(2);
    for(int i = 3;i <= 1000;++i){
        bool ok = 1;
        for(int j = 2;j <= sqrt(i);++j){
            if(!(i % j)) ok = 0;
        }
        if(ok) prime.push_back(i);
    }

    int n;
    while(cin >> n && n){
        cout << n << " : ";

        int cnt = 0;
        for(int i = 0;i < prime.size();++i){
            bool ok = 0;
            while(!(n % prime[i])){
                if(!ok){
                    ok = 1;
                    cnt++;
                }
                n /= prime[i];
            }
        }
        if(n != 1) cnt++;
        cout << cnt << "\n";
    }
    return 0;
}
