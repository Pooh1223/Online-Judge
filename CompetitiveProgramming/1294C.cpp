#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
map<int,int> factor;

int main(){
    prime.push_back(2);
    for(int i = 3;i <= 31623;i += 2){
        bool ok = 1;
        for(int j = 2;j <= sqrt(i);++j){
            if(!(i % j)){
                ok = 0;
                break;
            }
        }
        if(ok) prime.push_back(i);
    }

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        factor.clear();

        for(int i = 0;i < prime.size();++i){
            if(n == 1 || prime[i] > n) break;

            while(!(n % prime[i])){
                n /= prime[i];

                if(factor.find(prime[i]) == factor.end()){
                    factor[prime[i]] = 1;
                } else {
                    factor[prime[i]]++;
                }

            }
        }

        if(n != 1){
            if(factor.find(n) != factor.end()){
                factor[n] = 1;
            } else {
                factor[n]++;
            }
        }

        //for(auto kv : factor){
        //    cout << kv.first << " : " << kv.second << "\n";
        //}

        if(factor.size() == 0){
            cout << "NO\n";
        } else if(factor.size() == 1){
            auto fst = *factor.begin();
            if(fst.second >= 6){
                cout << "YES\n";
                cout << fst.first << " " << fst.first * fst.first << " " << int(pow(fst.first,(double)(fst.second - 3)) + 0.5) << "\n";
            } else {
                cout << "NO\n";
            }
        } else if(factor.size() == 2){
            auto fst = *factor.begin(),sd = *next(factor.begin(),1);
            if(fst.second >= 3 || sd.second >= 3){
                cout << "YES\n";
                if(fst.second >= 3){
                    cout << fst.first << " " << int(pow(fst.first,(double)(fst.second - 1)) + 0.5) << " " << int(pow(sd.first,(double)(sd.second)) + 0.5) << "\n";
                } else {
                    cout << int(pow(fst.first,(double)(fst.second)) + 0.5) << " " << sd.first << " " << int(pow(sd.first,(double)(sd.second - 1)) + 0.5) << "\n";
                }
            } else if(fst.second == 2 && sd.second == 2){
                cout << "YES\n";
                cout << fst.first << " " << sd.first << " " << fst.first * sd.first << "\n";
            } 
            else {
                cout << "NO\n";
            }
        } else {
            int cnt = 0;
            long long last = 1;
            cout << "YES\n";
            for(auto kv : factor){
                if(cnt < 2){
                    cout << int(pow(kv.first,(double)(int(kv.second + 0.5))) + 0.5) << " ";
                    cnt++;
                } else {
                    last *= int(pow(kv.first,(double)(int(kv.second + 0.5))) + 0.5);
                }
            }
            cout << last << "\n";
        }
    }

    return 0;
}
