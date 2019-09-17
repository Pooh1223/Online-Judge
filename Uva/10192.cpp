#include <bits/stdc++.h>
using namespace std;

int len[103][103];

int main(){
    int cnt = 1;
    string s1,s2;
    while(getline(cin,s1)){
        if(s1 == "#") break;
        getline(cin,s2);
        memset(len,0,sizeof(len));
        s1.insert(0," ");
        s2.insert(0," ");
        
        int len1 = s1.length() - 1,len2 = s2.length() - 1;

        for(int i = 1;i <= len1;++i){
            for(int j = 1;j <= len2;++j){
                if(s1[i] == s2[j]){
                    len[i][j] = len[i - 1][j - 1] + 1;            
                } else {
                    len[i][j] = max(len[i - 1][j],len[i][j - 1]);
                }
            }
        }

        cout << "Case #" << cnt++ << ": you can visit at most " << len[len1][len2] << " cities.\n";
    }
    return 0;
}
