#include <bits/stdc++.h>
using namespace std;

int chg(int now,string s){ // track which pos 1 is

    if(now == 1){

        if(s == "north") return 2;
        else if(s == "west") return 3;
        else if(s == "east") return 4;
        else if(s == "south") return 5;

    } else if(now == 2){

        if(s == "north") return 6;
        else if(s == "west") return 2;
        else if(s == "east") return 2;
        else if(s == "south") return 1;

    } else if(now == 3){

        if(s == "north") return 3;
        else if(s == "west") return 6;
        else if(s == "east") return 1;
        else if(s == "south") return 3;

    } else if(now == 4){

        if(s == "north") return 4;
        else if(s == "west") return 1;
        else if(s == "east") return 6;
        else if(s == "south") return 4;

    } else if(now == 5){

        if(s == "north") return 1;
        else if(s == "west") return 5;
        else if(s == "east") return 5;
        else if(s == "south") return 6;

    } else {

        if(s == "north") return 5;
        else if(s == "west") return 4;
        else if(s == "east") return 3;
        else if(s == "south") return 2;

    }
}

int dice(int pos1,int pos2){

    if(pos1 == 1){
        return pos1;
    } else if(pos2 == 1){
        return 2;
    } else if(pos2 == 6){
        return 5;
    } else if(pos1 == 2){
        return pos2;
    } else if(pos1 == 3){
        if(pos2 == 2) return 4;
        else if(pos2 == 5) return 3;
    } else if(pos1 == 4){
        if(pos2 == 2) return 3;
        else if(pos2 == 5) return 4;
    } else if(pos1 == 5){
        if(pos2 == 3) return 4;
        else if(pos2 == 4) return 3;
    } else {
        return 6;
    }
}

int main(){
    int n;
    while(cin >> n && n){
        int track1 = 1,track2 = 2;

        for(int i = 0;i < n;++i){
            string s;
            cin >> s;
            track1 = chg(track1,s);
            track2 = chg(track2,s);
        }
        //cout << "track1 : " << track1 << " , track2 : " << track2 << "\n";
        cout << dice(track1,track2) << "\n";
    }

    return 0;
}
