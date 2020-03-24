#include <bits/stdc++.h>
using namespace std;

struct node{
    int x,y;

    bool operator<(const node &a)const{
        return a.x + a.y < x + y;
    }
};

priority_queue<node> pq;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        pq = priority_queue<node>();

        for(int i = 0;i < n;++i){
            int a,b;
            cin >> a >> b;
            pq.push({a,b});
        }
        
        int nx = 0,ny = 0;
        string ans = "";

        while(!pq.empty()){
            int xx = pq.top().x;
            int yy = pq.top().y;
            pq.pop();

            if(xx < nx || yy < ny){
                ans = "NO";
                break;
            }

            while(nx < xx){
                ans += "R";
                nx++;
            }

            while(ny < yy){
                ans += "U";
                ny++;
            }
        }

        if(ans != "NO"){
            cout << "YES\n";
            cout << ans << "\n";
        } else cout << ans << "\n";
    }

    return 0;
}
