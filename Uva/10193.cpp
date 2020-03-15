#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 1;i <= n;++i){
        string s1,s2;
        cin >> s1 >> s2;

        bitset<32> b1(s1);
        bitset<32> b2(s2);

        long long nm1 = b1.to_ulong(),nm2 = b2.to_ulong();
        
        cout << "Pair #" << i << ": ";

        if(__gcd(nm1,nm2) == 1){
            cout << "Love is not all you need!\n";    
        } else {
            cout << "All you need is love!\n";
        }
    }

    return 0;
}
