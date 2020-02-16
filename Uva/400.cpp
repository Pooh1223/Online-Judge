#include <bits/stdc++.h>
using namespace std;

string file[103];

int main(){
    int n;

    while(cin >> n){

        int mx = 0;
        for(int i = 0;i < n;++i){
            cin >> file[i];
            mx = max(mx,(int)file[i].length());
        }

        sort(file,file + n);

        int col = 62 / (mx + 2),row;
        row = n % col ? (n / col) + 1 : n / col;

        for(int i = 0;i < 60;++i) cout << "-";
        cout << "\n";

        for(int i = 0;i < row;++i){
            for(int j = 0;j < col;++j){
                if(i + j * row >= n){
                    break;
                }
                cout << file[i + j * row];

                for(int k = 0;k < mx - file[i + j * row].length();++k){
                    cout << " ";
                }

                if(i + (j + 1) * row < n){
                    cout << "  ";
                } else {
                    cout << "\n";
                }
            }
        }
    }

    return 0;
}
