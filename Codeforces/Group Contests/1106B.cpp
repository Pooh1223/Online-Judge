#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
	ll amt,price,id;
	friend bool operator<(node a,node b){
		if(a.price != b.price) return a.price > b.price;
		return a.id > b.id;
	}
}food[100005];

priority_queue<node> pq;

int n,m;

void check(){
	for(int i = 1;i <= n;++i){
		cout << i << " ";
	}
	cout << "\n";
	for(int i = 1;i <= n;++i){
		cout << food[i].amt << " ";
	}
	cout << "\n";
	for(int i = 1;i <= n;++i){
		cout << food[i].price << " ";
	}
	cout << "\n";
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> food[i].amt;
	} 
	
	for(int i = 1;i <= n;++i){
		cin >> food[i].price;
		food[i].id = i;
		pq.push(node{food[i].amt,food[i].price,i});
	} 
	
	while(m--){
		bool isz = 0;
		ll sum = 0;
		int id,amt;
		cin >> id >> amt;
		if(food[id].amt >= amt){
			sum += amt * food[id].price;
			food[id].amt -= amt;
		} else {
			sum += food[id].amt * food[id].price;
			amt -= food[id].amt;
			food[id].amt = 0;
			while(amt && !pq.empty()){
				if(!food[pq.top().id].amt){
					pq.pop();
				} else if(pq.top().id == id){
					cout << "0\n";
					isz = 1;
					break;
				} else {
					if(food[pq.top().id].amt >= amt){
						sum += amt * food[pq.top().id].price;
						food[pq.top().id].amt -= amt;
						amt = 0;
					} else {
						sum += food[pq.top().id].amt * food[pq.top().id].price;
						amt -= food[pq.top().id].amt;
						food[pq.top().id].amt = 0;
						pq.pop();
					}
				}
			}
		}
		if(pq.empty()) cout << "0\n";
		else if(!isz) cout << sum << "\n";
		//check();
	}

	return 0;
}