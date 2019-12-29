#include <bits/stdc++.h>
using namespace std;

vector<long long> v;

int main(){
    long long nm = 1;
    v.push_back(nm);

    for(int i = 0;v.size() <= 5842;++i){
        for(int j = 0;v.size() <= 5842;++j){
            for(int k = 0;v.size() <= 5842;++k){
                for(int l = 0;v.size() <= 5842;++l){
                    nm *= 7;
                    if(nm > 2000000000){
                        nm = pow(5.0,k) * pow(3.0,j) * pow(2.0,i);
                        break;
                    }
                    v.push_back(nm);
                }
                nm *= 5;
                if(nm > 2000000000){
                    nm = pow(3.0,j) * pow(2.0,i);
                    break;
                }
                v.push_back(nm);
            }
            nm *= 3;
            if(nm > 2000000000){
                nm = pow(2.0,i);
                break;
            }
            v.push_back(nm);
        }
        nm *= 2;
        if(nm > 2000000000){
            break;
        }
        v.push_back(nm);
    }

    sort(v.begin(),v.end());
    
    int n;
    while(cin >> n && n){
        if(n % 100 == 11 || n % 100 == 12 || n % 100 == 13){
            cout << "The " << n << "th humble number is "; 
        } else if(n % 10 == 1){
            cout << "The " << n << "st humble number is ";
        } else if(n % 10 == 2){
            cout << "The " << n << "nd humble number is ";
        } else if(n % 10 == 3){
            cout << "The " << n << "rd humble number is ";
        } else {
            cout << "The " << n << "th humble number is ";
        }

        cout << v[n - 1] << ".\n";
    }

    return 0;
}
