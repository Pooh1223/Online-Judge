#include <bits/stdc++.h>
using namespace std;

list<int> player[5];
vector<int> draw[5];

//separate the string and push it in list
void push_card(int id,string s){
    if(s == "J"){
        player[id].push_back(-1);
    } else {
        string tmp = "";
        
        for(int i = 0;i < s.length() - 1;++i){
            tmp += s[i];
        }

        player[id].push_back(stoi(tmp));
    }
}

void throw_same(int id){
    
    for(list<int>::iterator j = player[id].begin();j != player[id].end();++j){
        if(*j == 0 || *j == -1) continue;
        for(list<int>::iterator k = next(j);k != player[id].end();++k){
            if(*j == *k){
                *j = 0;
                *k = 0;
                break;
            }
        }
    }

    for(list<int>::iterator j = player[id].begin();j != player[id].end();){
        list<int>::iterator tmp = next(j);
        if(*j == 0){
            player[id].erase(j);
        }
        j = tmp;
    }
}

void draw_card(int id,int turn){
    int next = (id + 1) % 3;
    int t = player[next].size();
    int ni = draw[id].size();
    int draw_id = (draw[id][(turn - 1) % ni] + t - 1) % t;
    
    int tmp;
    

    for(list<int>::iterator i = player[next].begin();i != player[next].end();++i){
        if(draw_id == 0){

            player[id].push_back(*i);
            player[next].erase(i);
            return;
        }
        draw_id--;
    }
    
}

bool checkEnd(){
    int cnt = 0;
    for(int i = 0;i < 3;++i){
        if(player[i].size() != 0) cnt++;
    }
    if(cnt < 3) return 1;
    else return 0;
}

void checkJoker(){
    bool ed = 0;
    for(int i = 0;i < 3 && !ed;++i){
        for(list<int>::iterator j = player[i].begin();j != player[i].end() && !ed;++j){
            if(*j == -1){
                ed = 1;
                if(i == 0) cout << "Alice\n";
                else if(i == 1) cout << "Bob\n";
                else cout << "Carol\n";
                break;
            }
        }
    }
}

void printCard(){
    for(int i = 0;i < 3;++i){
        if(i == 0) cout << "Alice : ";
        else if(i == 1) cout << "Bob : ";
        else cout << "Carol : ";
        for(list<int>::iterator j = player[i].begin();j != player[i].end();++j){
            cout << *j << " ";
        }
        cout << "\n";
    }
}

int main(){
    
    int t;
    cin >> t;

    while(t--){
        //enter card info
        for(int i = 0;i < 3;++i){
            player[i].clear();
            draw[i].clear();
            int k;
            cin >> k;
            while(k--){
                string s;
                cin >> s;
                push_card(i,s);            
            }
        }
        
        throw_same(0);
        throw_same(1);
        throw_same(2);

        //enter draw card info
        for(int i = 0;i < 3;++i){
            int k;
            cin >> k;

            while(k--){
                int nm;
                cin >> nm;
                draw[i].push_back(nm);
            }
        }
        
        bool ed = 0;
        
        int round = 1;

        if(checkEnd()){
            ed = 1;
            checkJoker();
        } else {
            for(int i = 1;round <= 100000;++i){
                //cout << "\nRound : " << i << "\n";

                draw_card((i - 1) % 3,round);
                //printCard();
                throw_same((i - 1) % 3);

                if(checkEnd()){
                    ed = 1;
                    checkJoker();
                    break;
                }
                //printCard();
                if(i % 3 == 0) round++;
            }

        }
                
        if(!ed) cout << "Good Game\n";
    }

    return 0;
}
