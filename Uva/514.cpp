#include <bits/stdc++.h>
using namespace std;

vector<int> sup,sta;
queue<int> v;
bool pos[1003];

int main(){
	int n;

	while(cin >> n && n){
		while(1){
			v = queue<int>();
			sup.clear();
			sta.clear();
			memset(pos,0,sizeof(pos));
			bool ed = 0;
			for(int i = 1;i <= n;++i) v.push(i);
			for(int i = 0;i < n;++i){
				int num;
				cin >> num;
				if(!num){
					ed = 1;
					cout << "\n";
					break;
				}
				sup.push_back(num);
			}
			if(ed) break;

			bool ok = 1;

			for(int i = 0;i < n;++i){

				if(v.empty() || pos[sup[i]]){
					if(sta.back() != sup[i]){
						ok = 0;
						break;
					} else {
						sta.pop_back();
					}
				} else {
					while(!v.empty()){
						if(v.front() != sup[i]){
							sta.push_back(v.front());
							pos[v.front()] = 1;
							v.pop();
						} else {
							v.pop();
							break;
						}
					}
				}
			}
			if(ok) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	
	return 0;
}