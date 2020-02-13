#include <bits/stdc++.h>
using namespace std;

struct node{
    int parent,lch,rch;
}tree[33];

string pre,in;
int prepos = 0;

void build(int l,int r,int len){
    if(len == 1){
        cout << pre[prepos];
        return;
    } else if(r < l){
        --prepos;
        return;
    }

    for(int i = l;i <= r;++i){
        if(in[i] == pre[prepos]){
            ++prepos;
            //cout << "inleft L : " << l << " ,R : " << i - 1 << " ,len : " << i - l << " ,prepos : " << prepos << "\n";
            build(l,i - 1,i - l);

            ++prepos;
            //cout << "inright L : " << i + 1 << " ,R : " << r << " ,len : " << r - i << " ,prepos : " << prepos << "\n";
            build(i + 1,r,r - i);
            cout << in[i];
            break;
        }
    }
}

int main(){

    while(cin >> pre >> in){
        prepos = 0;
        build(0,pre.length() - 1,pre.length());
        cout << "\n";
    }

    return 0;
}
