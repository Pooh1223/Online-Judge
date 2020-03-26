#include <bits/stdc++.h>
using namespace std;

long long nm[30];
vector<long long> sure,alter;
map<long long,int> oriList;
bool ed = 0;

int sepa(string s){
    string tmp = "";
    int cnt = 0;
    for(int i = 0;i < s.length();++i){
        if(s[i] == ' '){
            nm[cnt++] = stoll(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }

    nm[cnt++] = stoll(tmp);

    for(int i = 0;i < cnt;++i){
        if(oriList.find(nm[i]) == oriList.end()){
            oriList[nm[i]] = 1;
        } else {
            oriList[nm[i]]++;
        }
    }

    return cnt;
}

bool isSq(long long nm){
    if((long long)(sqrt(nm) + 0.5) * (long long)(sqrt(nm) + 0.5) == nm) return 1;
    else return 0;
}

bool checkMulti(vector<long long> v){
    map<long long,int> tmp = oriList;

    for(int i = 0;i < v.size();++i){
        for(int j = 0;j < v.size();++j){
            if(tmp.find(v[i] * v[j]) == tmp.end()){
                return 0;
            } else {
                tmp[v[i] * v[j]]--;
                if(tmp[v[i] * v[j]] == 0) tmp.erase(v[i] * v[j]);
            }
        }
    }

    return 1;
}

void backtrack(int d,int pos,int sz){
    if(ed) return;

    if(d == sz){
        if(checkMulti(sure)){
            ed = 1;

            cout << "Yes\n";
            sort(sure.begin(),sure.end());
            for(int i = 0;i < sure.size();++i){
                cout << sure[i] << " ";
            }
            cout << "\n";

            return;
        }
    } else {
        for(int i = pos;i < alter.size();++i){
            sure.push_back(alter[i]);
            backtrack(d + 1,pos + 1,sz);
            sure.pop_back();
        }
    }
}

int main(){
    string s;
    while(getline(cin,s)){
        sure.clear();
        alter.clear();
        oriList.clear();
        ed = 0;

        int len = sepa(s);
        
        //cout << "len : ";
        //for(int i = 0;i < len;++i) cout << nm[i] << " ";
        //cout << "\n";
        
        if(len == 1){
            if((long long)(sqrt(nm[0]) + 0.5) * (long long)(sqrt(nm[0]) + 0.5) == nm[0]){
                cout << "Yes\n" << (long long)(sqrt(nm[0]) + 0.5) << "\n";
            } else cout << "No\n";
        } else {
            int oriSz = (long long)(sqrt(len) + 0.5);
            
            long long mn = 1e18 + 3,mx = -1;

            for(int i = 0;i < len;++i){
                mx = max(nm[i],mx);
                mn = min(nm[i],mn);
            }
            
            //push_back min and max square num
            //
            for(int i = 0;i < (long long)(sqrt(oriList[mn]) + 0.5);++i){
                sure.push_back((long long)(sqrt(mn) + 0.5));
            }
            
            for(int i = 0;i < (long long)(sqrt(oriList[mx]) + 0.5);++i){
                sure.push_back((long long)(sqrt(mx) + 0.5));
            }
            
            //check if size is already fit the require
            
            if(sure.size() == oriSz && checkMulti(sure)){
                cout << "Yes\n";
                for(int i = 0;i < sure.size();++i){
                    cout << sure[i] << " ";
                }
                cout << "\n";

                continue;
            }
            
            //find other possible square num

            for(int i = 0;i < len;++i){
                if(nm[i] != mx && nm[i] != mn && isSq(nm[i])){
                    for(int j = 0;j < (long long)(sqrt(oriList[nm[i]]) + 0.5);++j){
                        alter.push_back((long long)(sqrt(nm[i]) + 0.5));
                    }
                }
            }

            //back track
            
            backtrack(sure.size(),0,oriSz);

            if(!ed) cout << "No\n";
        }
    }
    return 0;
}
