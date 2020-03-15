#include <bits/stdc++.h>
using namespace std;

vector<int> big,small;

int input(){
    int nm;
    string s1,s2;
    
    while(cin >> nm >> s1 >> s2){
        if(s1 == "too" && s2 == "high"){
            big.push_back(nm);
        } else if(s1 == "too" && s2 == "low"){
            small.push_back(nm);
        } else {
            return nm;
        }
    } 
}

bool isHonest(int ans){
    for(int i = 0;i < big.size();++i){
        if(ans >= big[i]){
            return 0;
        }
    }

    for(int i = 0;i < small.size();++i){
        if(ans <= small[i]){
            return 0;
        }
    }

    return 1;
}

int main(){
    int nm;
    while(cin >> nm && nm){
        
        big.clear();
        small.clear();

        string s1 = "",s2 = "";
        cin >> s1 >> s2;

        int ans = 0;

        if(s1 == "too" && s2 == "high"){
            big.push_back(nm);
            ans = input();
            
            if(isHonest(ans)) cout << "Stan may be honest\n";
            else cout << "Stan is dishonest\n";
        } else if(s1 == "too" && s2 == "low"){
            small.push_back(nm);
            ans = input();

            if(isHonest(ans)) cout << "Stan may be honest\n";
            else cout << "Stan is dishonest\n";
        } else {
            cout << "Stan may be honest\n";
        }
    }
    return 0;
}
