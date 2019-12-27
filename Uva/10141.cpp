#include <bits/stdc++.h>
using namespace std;

struct company{
    string name;
    int id,amt;
    double mn;

    bool operator<(const company &a)const{
        if(a.amt != amt) return a.amt < amt;
        if(a.mn != mn) return a.mn > mn;
        return a.id > id;
    }
}c[10003];

int main(){
    int n,p,cnt = 1;
    while(cin >> n >> p){
        if(!n && !p) break;
        if(cnt != 1) cout << "\n";

        for(int i = 0;i < 10003;++i){
            c[i].name = "";
            c[i].id = i;
            c[i].mn = 0;
            c[i].amt = 0;
        }
        
        while(getchar() != '\n');
        string s;

        for(int i = 0;i < n;++i) getline(cin,s);
        
        for(int k = 0;k < p;++k){
            getline(cin,c[k].name);
            cin >> c[k].mn >> c[k].amt;
            while(getchar() != '\n');
            for(int i = 0;i < c[k].amt;++i) getline(cin,s);
        }
        
        sort(c,c + p);
        
        cout << "RFP #" << cnt++ << "\n";
        cout << c[0].name << "\n";
    }
    return 0;
}
