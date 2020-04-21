#include <bits/stdc++.h>
using namespace std;

//int djs[1003][1003]; //group,element
set<int> grp[1003];

int main(){

    int t,cnt = 1;

    while(cin >> t && t){
        bool fst = 0;

        for(int i = 0;i < 1003;++i) grp[i].clear();
        
        queue<int> q[1003],order;

        for(int i = 0;i < t;++i){
            int m;
            cin >> m;

            for(int j = 0;j < m;++j){
                int nm;
                cin >> nm;
                grp[i].insert(nm);
            }
        }

        string s;

        while(cin >> s){
            if(s == "STOP"){
                cout << "\n";
                break;
            }
            else if(s == "ENQUEUE"){
                int nm;
                cin >> nm;
                
                int groupId;

                for(int i = 0;i < 1003;++i){
                    if(grp[i].count(nm)){
                        groupId = i;
                        break;
                    }
                }

                if(q[groupId].size() != 0){
                    //already has other member in queue
                    q[groupId].push(nm);
                } else {
                    //first member of the group
                    order.push(groupId);
                    q[groupId].push(nm);
                }
 
            } else {
                int id = order.front();
                int nm = q[id].front();
                
                if(!fst) {
                    cout << "Scenario #" << cnt++ << "\n";
                    fst = 1;
                }
                cout << nm << "\n";
                q[id].pop();

                if(q[id].size() == 0){
                    order.pop();
                }
            }
        }
    }

    return 0;
}
