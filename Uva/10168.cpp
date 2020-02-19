#include <bits/stdc++.h>
using namespace std;

bool prime[3205];

bool isprime(int nm){
    if(nm < 3205) return prime[nm];
    else {
        bool ok = 1;
        for(int i = 2;i < 3205;++i){
            if(prime[i] && !(nm % i)){
                ok = 0;
            }
        }

        return ok;
    }
}

string divide(int nm){
    string s = "";
    if(nm < 4){
        s = "Impossible";
        return s;
    }
    if(nm % 2){

        if(isprime(nm - 2)){
            s += "2 " + to_string(nm - 2);
            return s;
        } else {
            s = "Impossible";
            return s;
        }

    } else {
        for(int i = 2;i < 3205;++i){
            if(isprime(i) && isprime(nm - i)){
                s += to_string(i) + " " + to_string(nm - i);
                return s;
            }
        }
        
        s = "Impossible";
        return s;
    }
}

int main(){
    
    for(int i = 2;i < 3205;++i) prime[i] = 1;
    for(int i = 2;i < 3205;++i){
        if(prime[i]){
            for(int j = i * i;j < 3205;j += i){
                prime[j] = 0;
            }
        }
    }

    int n;
    while(cin >> n){
        if(n < 8){
            cout << "Impossible.\n";
            continue;
        }

        string s1,s2;

        if(n % 2){
            bool fin = 0;
            for(int i = 2;i < n / 2 + 1;i += 2){
                s1 = divide(i);
                s2 = divide(n - i);
                if(s1 != "Impossible" && s2 != "Impossible"){
                    cout << s1 << " " <<s2 << "\n";
                    fin = 1;
                    break;
                }
            }
            if(!fin) cout << "Impossible.\n";
        } else {
            
            if((n / 2) % 2){
                s1 = divide(n / 2 - 1);
                s2 = divide(n / 2 + 1);
            } else {
                s1 = divide(n / 2);
                s2 = s1;
            }
            
            if(s1 != "Impossible" && s2 != "Impossible"){
                cout << s1 << " " << s2;
            } else {
                cout << s1 << ".";
            }
            cout << "\n";
        }
    }

    return 0;
}
