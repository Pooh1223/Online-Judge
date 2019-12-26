#include <bits/stdc++.h>
using namespace std;

struct judge{
    int id,prob[13],time,tp;
    bool out = 0;

    bool operator<(const judge &a)const{
        if(a.tp != tp) return a.tp < tp;
        if(a.time != time) return a.time > time;
        return a.id > id;
    }
}p[103];

int main(){
    int t;
    cin >> t;
    while(getchar() != '\n');

    string s;
    getline(cin,s);

    for(int tt = 0;tt < t;++tt){
        if(tt) cout << "\n";

        for(int i = 0;i < 103;++i){
            p[i].id = i;
            p[i].time = 0;
            p[i].tp = 0;
            p[i].out = 0;
            for(int j = 0;j < 13;++j){
                p[i].prob[j] = 0;
            }
        }

        while(getline(cin,s)){
            if(s.length() == 0) break;
            
            s += " ";
            string tmp = "";
            int who,prob,time,cnt = 0;

            for(int i = 0;i < s.length();++i){
                if(s[i] != ' ') tmp += s[i];
                else {
                    if(cnt == 0){
                        who = stoi(tmp);
                        p[who].out = 1;
                    } else if(cnt == 1){
                        prob = stoi(tmp);
                    } else if(cnt == 2){
                        time = stoi(tmp);
                    } else {
                        if(p[who].prob[prob] == -1) continue;

                        if(tmp == "C"){ // note -1 means solved
                            p[who].time += 20 * p[who].prob[prob] + time;
                            p[who].tp++;
                            p[who].prob[prob] = -1;
                        } else if(tmp == "I"){
                            p[who].prob[prob]++;
                        }
                    }

                    tmp = "";
                    cnt++;
                }
            }
            cnt = 0;
        }
        sort(p,p + 101);
        for(int i = 0;i < 103;++i){
            if(p[i].out){
                cout << p[i].id << " " << p[i].tp << " " << p[i].time << "\n";
            }
        }
    }

    return 0;
}
