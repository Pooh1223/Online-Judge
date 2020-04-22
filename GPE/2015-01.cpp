#include <bits/stdc++.h>
using namespace std;

map<int,int> s1,s2;

int main(){
    int m,n;

    while(~scanf("%d %d",&m,&n)){
        for(int i = 0;i < m;++i){
            if(s1.size() == 0 && s2.size() == 0){
                if(i % 2){
                    for(int j = 0;j < n - i;++j){
                        int k;
                        scanf("%d",&k);

                        if(s1.find(k) != s1.end())
                            s1[k]++;
                        else s1[k] = 1;
                    }
                } else {
                    for(int j = 0;j < n - i;++j){
                        int k;
                        scanf("%d",&k);                    

                        if(s2.find(k) != s2.end())
                            s2[k]++;
                        else s2[k] = 1;
                    }
                }
                
            } else {
                if(i % 2){
                    for(int j = 0;j < n - i;++j){
                        int k;
                        scanf("%d",&k);

                        s2[k]--;
                        if(s2[k] == 0){
                            s2.erase(k);
                        }

                        if(s1.find(k) != s1.end())
                            s1[k]++;
                        else s1[k] = 1;
                        
                    }
                    cout << (*s2.begin()).first << "\n";
                    s2.clear();
                } else {
                    for(int j = 0;j < n - i;++j){
                        int k;
                        scanf("%d",&k);

                        s1[k]--;
                        if(s1[k] == 0){
                            s1.erase(k);
                        }

                        if(s2.find(k) != s2.end())
                            s2[k]++;
                        else s2[k] = 1;
                    }
                    cout << (*s1.begin()).first << "\n";
                    s1.clear();
                }
            }
        }
    }

    
    return 0;
}
