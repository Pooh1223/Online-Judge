#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        vector<int> R,D;
        bool ok = 0;

        for(int i = 0;i < n;++i){
            char c;
            cin >> c;

            if(c == 'R'){
                R.push_back(i);
            } else if(c == 'D'){
                D.push_back(i);
            } else if(c == 'Z' && !ok){
                cout << "0\n";
                ok = 1;
            }
        }

        if(ok) continue;

        int mn = 1e9;

        for(int i = 0;i < R.size();++i){
            for(int j = 0;j < D.size();++j){
                mn = min(mn,abs(R[i] - D[j]));
            }
        }

        cout << mn << "\n";
    }

    return 0;
}
