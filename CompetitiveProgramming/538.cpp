#include <bits/stdc++.h>
using namespace std;

long long cnt = 0;

void merge(vector<int> &v,int l,int m,int r){
    int lcnt = l,rcnt = m;

    vector<int> tmp;

    while(lcnt < m || rcnt < r){
        if(lcnt >= m){
            tmp.push_back(v[rcnt]);
            rcnt++;
        } else if(rcnt >= r){
            tmp.push_back(v[lcnt]);
            lcnt++;
        } else {
            if(v[lcnt] > v[rcnt]){
                tmp.push_back(v[rcnt]);
                rcnt++;
                cnt += (m - lcnt);
            } else {
                tmp.push_back(v[lcnt]);
                lcnt++;
            }
        }
    }

    for(int i = l;i < r;++i){
        v[i] = tmp[i - l];
    }
}

void mergeSort(vector<int> &v,int l,int r){
    if(r - l == 1) return;

    int m = (l + r) / 2;

    mergeSort(v,l,m);
    mergeSort(v,m,r);

    merge(v,l,m,r);
}

int main(){
    int t;
    cin >> t;

    while(t--){ 
        cnt = 0;

        int n;
        cin >> n;

        vector<int> v(n + 3);

        for(int i = 0;i < n;++i){
            cin >> v[i];            
        }

        mergeSort(v,0,n);
        
        //for(int i = 0;i < n;++i) cout << v[i] << " ";
        //cout << "\n";

        cout << cnt << "\n";
    }

    return 0;
}
