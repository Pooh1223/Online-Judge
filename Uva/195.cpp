#include <bits/stdc++.h>
using namespace std;

set<string> s;
char order[55];

int main(){
    int n;
    scanf("%d",&n);
    s.clear();
    for(int i = 1;i < 52;i += 2){
        order[i - 1] = char('A' + i / 2);
        order[i] = char('a' + i / 2);
    }
    while(n--){
        char str[103];
        int nm[103];
        string ss = "";

        scanf("%s",&str);
        int len = strlen(str);
        for(int i = 0;i < len;++i){
            ss += str[i];    
            for(int j = 0;j < 52;++j){
                if(order[j] == str[i]){
                    nm[i] = j;
                    break;
                }
            }
        }
        if(s.count(ss)) continue;
        s.insert(ss);
        
        sort(nm,nm + len);
        
        do{
            for(int i = 0;i < len;++i){
                cout << char(order[nm[i]]);
            }
            cout << "\n";
        }while(next_permutation(nm,nm + len));

    }
    return 0;
}
