#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int len[10003];

int main(){
    int n,cnt = 1;
    while(cin >> n){
        if(n == -1) break;
        if(cnt != 1) cout << "\n";

        for(int i = 0;i < 10003;++i) len[i] = 1;
        v.clear();
        v.push_back(n);

        while(cin >> n){
            if(n == -1) break;
            v.push_back(n);
        }

        for(int i = 0;i < v.size();++i){
            for(int j = i + 1;j < v.size();++j){
                if(v[j] <= v[i]) len[j] = max(len[i] + 1,len[j]);
            }
        }
        cout << "Test #" << cnt++ << ":\n";
        cout << "  maximum possible interceptions: ";
        int mx = -1;
        for(int i = 0;i < v.size();++i){
            mx = max(mx,len[i]);
        }
        cout << mx << "\n";
    }
    return 0;
}
