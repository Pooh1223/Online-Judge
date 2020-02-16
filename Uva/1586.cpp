#include <bits/stdc++.h>
#define C 12.01
#define H 1.008
#define O 16.00
#define N 14.01
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        double sum = 0;

        for(int i = 0;i < s.length();){
            //is num
            if(i + 1 < s.length() && s[i + 1] - '0' >= 0 && s[i + 1] - '0' <= 9){
                bool ok = 0;

                string tmp = "";
                for(int j = i + 1;j < s.length();++j){
                    if(s[j] - '0' >= 0 && s[j] - '0' <= 9) tmp += s[j];
                    else {
                        ok = 1;
                        if(s[i] == 'C'){
                            sum += C * (double)stoi(tmp);
                        } else if(s[i] == 'N'){
                            sum += N * (double)stoi(tmp);
                        } else if(s[i] == 'H'){
                            sum += H * (double)stoi(tmp);
                        } else {
                            sum += O * (double)stoi(tmp);
                        }
                        
                        i = j;
                        break;
                    }
                }

                if(!ok){
                    if(s[i] == 'C'){
                        sum += C * (double)stoi(tmp);
                    } else if(s[i] == 'N'){
                        sum += N * (double)stoi(tmp);
                    } else if(s[i] == 'H'){
                        sum += H * (double)stoi(tmp);
                    } else {
                        sum += O * (double)stoi(tmp);
                    }
                    break;
                }
            } else {
                if(s[i] == 'C'){
                    sum += C;
                } else if(s[i] == 'N'){
                    sum += N;
                } else if(s[i] == 'H'){
                    sum += H;
                } else {
                    sum += O;
                }
                i++;
            }
        }

        printf("%.3f\n",sum);
    }

    return 0;
}
