#include <bits/stdc++.h>
using namespace std;

char input(){
    char tmp = getchar();
    while(tmp == ' ' || tmp == '\n')
        tmp = getchar();
    return tmp;
}

bool traversal(int nm,bool *leaf){
    
    int t = 0;
    bool l = 0,r = 0,fit = 0;
    char c;
    
    scanf("%d",&t);
    c = input();

    if(c == '('){
        if(traversal(nm - t,&l)) fit = 1;
        c = input();
        if(traversal(nm - t,&r)) fit = 1;
        c = input();
        if(l && r) fit = (t == nm);
    } else *leaf = 1;

    return fit;
}

int main(){
    int nm;
    while(cin >> nm){
        input();
        bool jizz = 0;
        if(traversal(nm,&jizz)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
