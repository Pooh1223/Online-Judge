#include <bits/stdc++.h>
using namespace std;

long long nm[1003];

int main(){
    int n;
    int cnt = 1;
    while(cin >> n && n){
        cout << "Case " << cnt++ << ":\n";
        for(int i = 0;i < n;++i){
            cin >> nm[i];
        }
            
        vector<long long> v;
        v.clear();

        for(int i = 0;i < n;++i){
            for(int j = i + 1;j < n;++j){
                v.push_back(nm[i] + nm[j]);
            }
        }

        sort(v.begin(),v.end());

        int m;
        cin >> m;
        while(m--){
            long long k;
            cin >> k;
            if(k >= v.back()){
                cout << "Closest sum to " << k << " is " << v.back() << ".\n";
                continue;
            } else if(k <= v[0]){
                cout << "Closest sum to " << k << " is " << v[0] << ".\n";
                continue;
            }
            for(int i = 0;i < v.size();++i){
                if(v[i] >= k){
                    if(v[i] == k){
                        cout << "Closest sum to " << k << " is " << k << ".\n";
                        break;
                    } else if(abs(v[i] - k) >= abs(v[i - 1] - k)){
                        cout << "Closest sum to " << k << " is " << v[i - 1] << ".\n";
                        break;
                    } else {
                        cout << "Closest sum to " << k << " is " << v[i] << ".\n";
                        break;
                    }
                }
            }
        } 
    }
    return 0;    
}
