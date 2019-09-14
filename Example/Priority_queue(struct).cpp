#include <iostream>
#include <queue>
using namespace std;
struct t{
	int a,b;
	bool operator<(const t&q)const{
		return a > q.a;
	}	
};
priority_queue<t> pq;
int main(){
	pq.push((t){1,4});
	pq.push((t){2,7});
	pq.push((t){7,436});
	pq.push((t){7122,3});
	cout << "(" << pq.top().a << "," << pq.top().b << ")" << "\n";
	pq.pop();
	pq.push((t){100,235});
	cout << "(" << pq.top().a << "," << pq.top().b << ")" << "\n";
	pq.push((t){87,66});
	pq.push((t){63,45345});
	pq.push((t){30,66});
	pq.push((t){103,11});
	while(!pq.empty()){
		cout << "(" << pq.top().a << "," << pq.top().b << ")" << "\n";
		pq.pop();
	}
	return 0;
}