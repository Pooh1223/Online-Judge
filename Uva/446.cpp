#include <bits/stdc++.h>
using namespace std;

stringstream ss;

long long hexToDec(string s){
    ss.str("");
    ss.clear();

    long long nm;
    ss << s;
    ss >> std::hex >> nm;
    
    cout << bitset<13>(nm).to_string();

    return nm;
}

int main(){
    int n;
    cin >> n;

    while(n--){
        string a,b,c;
        cin >> a >> b >> c;

        long long na = hexToDec(a);
        cout << " " << b << " ";
        long long nb = hexToDec(c);

        if(b == "+") cout << " = " << na + nb << "\n";
        else cout << " = " << na - nb << "\n";
    }

    return 0;
}
