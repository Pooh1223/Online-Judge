#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(getchar() != '\n');

    while(t--){
        string s1,s2;

        getline(cin,s1);

        vector<int> pos;

        for(int i = 0;i < s1.length();++i){
            if(s1[i] == '<' || s1[i] == '>') pos.push_back(i + 1);
            else cout << s1[i];
        }

        cout << "\n";

        getline(cin,s2);

        for(int i = 0;i < s2.length();++i){
            if(s2[i] != '.') cout << s2[i];
            else {

                for(int j = pos[2];j < s1.length();++j){
                    if(s1[j] != '>') cout << s1[j];
                    else break;
                }

                for(int j = pos[1];j < s1.length();++j){
                    if(s1[j] != '<') cout << s1[j];
                    else break;
                }
                
                for(int j = pos[0];j < s1.length();++j){
                    if(s1[j] != '>') cout << s1[j];
                    else break;
                }

                for(int j = pos[3];j < s1.length();++j){
                    cout << s1[j];
                }

                break;
            }
        }

        cout << "\n";
    }

    return 0;
}
