#include <iostream>
#include <cstring>
using namespace std;

int price[5] = {5, 2, 6, 11, 17};
int number[5] = {4, 5, 5, 3, 2};    // 各種錢幣的供應數量
bool c[1000+1];
 
void change(int m){
    memset(c, 0, sizeof(c));
    c[0] = true;
 
    for (int i = 0; i < 5; ++i){
        // 各種餘數分開處理
        for (int k = 0; k < price[i]; ++k){
            int left = number[i];   // 補充彈藥
            // 由低價位到高價位
            for (int j = k; j <= m; j += price[i]){
                // 先前的面額已能湊得，當前面額可以省著用。
                if (c[j]) left = number[i];   // 補充彈藥
                // 過去都無法湊得，一定要用目前面額硬湊。
                else if (left > 0){
                    left--; // 用掉一個錢幣
                    c[j] = true;
                }
            }
        }
    }
    if (c[m]) cout << "Yes\n";
    else cout << "No\n";
}

int main(){
    cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        change(n);
    }
    return 0;
}