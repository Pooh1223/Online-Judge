#include <bits/stdc++.h>
using namespace std;

int nm[200003];
bool used[200003];

set<int> emptyPos;
vector<int> same,lft; //num,pos

int main(){
    int n;
    cin >> n;

    for(int i = 0;i < n;++i){
        cin >> nm[i];

        if(nm[i]) used[nm[i]] = 1;
        else emptyPos.insert(i + 1);
    }

    for(int i = 1;i <= n;++i){
        if(!used[i]){ //missing num
            if(emptyPos.count(i)){ //has same num & pos
                same.push_back(i);
                used[i] = 1;
            } else lft.push_back(i);
        }
    }

    if(same.size() == 1){
        for(int i = 0;i < n;++i){
            if(!nm[i] && i + 1 != same[0]){
                nm[i] = same[0];
                break;
            }
        }   
    } else {
        for(int i = 0;i < same.size();++i){
            if(i == same.size() - 1){
                nm[same[0] - 1] = same[i];
            } else {
                nm[same[i + 1] - 1] = same[i];
            }
        }
    }
    
    int cnt = 0;

    for(int i = 0;i < n;++i){
        if(!nm[i]){
            cout << lft[cnt++] << " ";
        } else {
            cout << nm[i] << " ";
        }
    }

    return 0;
}
