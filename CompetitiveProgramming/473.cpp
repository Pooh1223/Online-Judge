#include <bits/stdc++.h>
using namespace std;

string bingo[53][53];
bool used[53][53];
int x = 0;

void printAns(int n){

    int row = 0,col = 0;

    for(int i = 0;i < n;++i){
        bool ok = 1;
        for(int j = 0;j < n;++j){
            if(!used[i][j]){
                ok = 0;
                break;
            }
        }
        if(ok) row++;
    }

    for(int j = 0;j < n;++j){
        bool ok = 1;
        for(int i = 0;i < n;++i){
            if(!used[i][j]){
                ok = 0;
                break;
            }
        }
        if(ok) col++;
    }
 
    cout << row << " " << col << "\n";
}


int containsNum(string s){
    bool is = 0;
    int cnt = 0;

    for(int i = 0;i < s.length();++i){
        is = 0;

        while(i < s.length() && s[i] - '0' >= 0 && s[i] - '0' <= 9){
            if(!is){
                cnt++;
                is = 1;
            }
            ++i;
        }
    
    }

    return cnt;
}

bool isSt(string s){
    int plus = 0;

    for(int i = 0;i < s.length();++i){
        if(s[i] == '+') plus++;
    }

    return plus == 2;
}

void checkNum(string s,int n){
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            if(bingo[i][j] == s){
                used[i][j] = 1;
                printAns(n);
            }
        }
    }
}

void separate(string s,int n,int mx){
    string tmp = "";
    int x = mx,y = 0;

    for(int i = 0;i < s.length();++i){
        while(i < s.length() && s[i] - '0' >= 0 && s[i] - '0' <= 9){
            tmp += s[i];
            ++i;
        }

        if(tmp.length() != 0){
            bingo[x][y] = tmp;
            tmp = "";
            y++;
        }
    }
}

int main(){
    string s;
    int len = 0;

    while(getline(cin,s)){
        int sz = containsNum(s);

        if(sz != 0){
            if(sz == 1){ //check part
                if(s.length() != 9){
                    string tmp = "";
                    for(int i = 0;i < 9 - s.length();++i) tmp += "0";
                    tmp += s;
                    s = tmp;
                }
                checkNum(s,len);
            } else {
                len = sz;
                separate(s,len,x);
                x++;
            }
        } else {
            if(isSt(s)){

                memset(used,0,sizeof(used));
                x = 0;
                len = 0;
            }
        }
    }

    return 0;
}
