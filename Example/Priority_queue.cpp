#include <iostream>
#include <queue>
#include <functional>
using namespace std;
priority_queue< int, vector<int>, greater<int> > pq;
int main(){
	pq.push(1);
	pq.push(2);
	pq.push(7);
	pq.push(7122);
	cout << pq.top() << "\n";
	pq.pop();
	pq.push(100);
	cout << pq.top() << "\n";
	pq.push(87);
	pq.push(63);
	pq.push(30);
	pq.push(103);
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}