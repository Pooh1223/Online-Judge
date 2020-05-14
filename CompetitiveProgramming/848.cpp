#include <bits/stdc++.h>
using namespace std;

struct point{
    long long x,h;

    bool operator<(const point &a)const{
        if(a.x != x) return a.x > x;
        return a.h > h;
    }
};

vector<point> v;
multiset<long long> Set;

void peri(vector<pair<long long,long long> > &ans){
    long long sum = ans[0].second;

    // for(int i = 0;i < ans.size();++i){
    //     if(i == 0){
    //         sum += ans[i].second;
    //     } else {
    //         sum += abs(ans[i].second - ans[i - 1].second);
    //         if(ans[i - 1].second != 0) sum += abs(ans[i].first - ans[i - 1].first);
    //     }
    // }

    for(int i = 1;i < ans.size();++i){
        sum += abs(ans[i].second - ans[i - 1].second);
    }

    for(int i = 1;i < ans.size();++i){
        sum += (ans[i - 1].second == 0) ? 0 : abs(ans[i].first - ans[i - 1].first);
    }

    cout << sum << " ";
}

void area(vector<pair<long long,long long> > &ans){
    long long sum = 0;

    for(int i = 1;i < ans.size();++i){
        sum += (ans[i].first - ans[i - 1].first) * (ans[i - 1].second);
    }

    cout << sum << "\n";
}

int main(){

    int n;
    cin >> n;

    for(int i = 0;i < n;++i){
        long long a,b,c;
        cin >> a >> b >> c;
        
        v.push_back({a,-b});
        v.push_back({a + c,b});
    }
    
    sort(v.begin(),v.end());

    vector<pair<long long,long long> > ans;

    //floor height
    Set.insert(0);

    int preh = 0;

    // for(int i = 0;i < v.size();++i) cout << v[i].x << " " << v[i].h << "\n";

    for(int i = 0;i < v.size();++i){
        if(v[i].h < 0){
            Set.insert(-v[i].h);

            long long curh = *Set.rbegin();

            //cout << "curh : " << i << " " << curh << "\n";

            if(preh != curh){
                ans.push_back(make_pair(v[i].x,curh));
            }
            
            preh = curh;
        } else {
            multiset<long long>::iterator it = Set.find(v[i].h);
            Set.erase(it);

            long long curh = *Set.rbegin();

            //cout << "curh : " << i << " " << curh << "\n";

            if(preh != curh){
                ans.push_back(make_pair(v[i].x,curh));
            }

            preh = curh;
        }
    }

    // for(int i = 0;i < ans.size();++i){
    //     cout << ans[i].first << " " << ans[i].second << "\n";
    // }

    peri(ans);
    area(ans);
    
    return 0;
}
