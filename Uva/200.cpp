#include <bits/stdc++.h>
using namespace std;

vector<int> v[30];
vector<int> ans;
int in[30];
bool appear[30],used[30];

int main(){
    //an edge from a to b means a prior than b
    int cnt = 0;
    string s1 = "",s2 = "";

    while(cin >> s1){
        if(s1 == "#") break;
        if(s2 == ""){
            s2 = s1;
            continue;
        }

        if(s2[0] != s1[0]){
            v[s2[0] - 'A'].push_back(s1[0] - 'A');
            in[s1[0] - 'A']++;
            appear[s1[0] - 'A'] = 1;
            appear[s2[0] - 'A'] = 1;
        } else {

            for(int i = 0;i < min(s1.length(),s2.length());++i){
                if(s1[i] != s2[i]){ 
                    v[s2[i] - 'A'].push_back(s1[i] - 'A');
                    in[s1[i] - 'A']++;
                    appear[s1[i] - 'A'] = 1;
                    appear[s2[i] - 'A'] = 1;
                    break;
                }
            }
        }

        s2 = s1;
    }

    if(s2 == "") cout << s1[0] << "\n";
    else {
        queue<int> q;

        for(int i = 0;i < 26;++i){
            if(appear[i] && !in[i]){
                q.push(i);
                used[i] = 1;
                break;
            }
        }

        while(!q.empty()){
            int now = q.front();
            q.pop();
            cout << char(now + 'A');
            
            for(int i = 0;i < v[now].size();++i){
                in[v[now][i]]--;
            }

            for(int i = 0;i < 26;++i){
                if(!used[i] && appear[i] && !in[i]){
                    q.push(i);
                    used[i] = 1;
                }
            }
        }

        cout << "\n";
    }
    
    //for(int i = 0;i < 26;++i){
    //    for(int j = 0;j < v[i].size();++j){
    //        cout << char(i + 'A') << " > " << char(v[i][j] + 'A') << "\n";
    //    }
    //}

	return 0;
}
