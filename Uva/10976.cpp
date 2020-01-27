#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;

    while(cin >> n){
        int cnt = 0;
        string s = "";

        for(int i = n + 1;i <= 2 * n;++i){
            int x = n * i / (i - n);

            if(x * (i - n) < n * i) continue;
            
            cnt++;
            s += "1/" + to_string(n) + " = 1/" + to_string(x) + " + 1/" + to_string(i) + "\n";
        }

        cout << cnt << "\n";
        cout << s;
    }

    return 0;
}
