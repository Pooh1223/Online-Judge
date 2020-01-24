#include <bits/stdc++.h>
using namespace std;

bool prime[2005];
int ascii[130];

int main(){
    for(int i = 2;i < 2005;++i) prime[i] = 1;
    for(int i = 2;i < 2005;++i){
        if(prime[i]){
            for(int j = i * i;j < 2005;j += i){
                prime[j] = 0;
            }
        }
    }
    
    int n;
    string s;

    cin >> n;
    for(int k = 1;k <= n;++k){
        memset(ascii,0,sizeof(ascii));

        cin >> s;

        for(int i = 0;i < s.length();++i){
            ascii[int(s[i])]++;
        }

        bool emp = 1;

        cout << "Case " << k << ": ";

        for(int i = 0;i <= 128;++i){
            if(prime[ascii[i]]){
                cout << char(i);
                emp = 0;
            }
        }
        if(emp) cout << "empty";
        cout << "\n";
    }

    return 0;
}
