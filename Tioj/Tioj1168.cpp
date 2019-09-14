#include <bits/stdc++.h>
#include "lib1168.h"
using namespace std;
struct node{
	int n,p;
	bool operator <(const node&a) const{
		return n < a.n;
	}
	bool operator >(const node&b) const{
		return n > b.n;
	}
	node(int n,int p): n(n),p(p) {}
};
priority_queue<node,vector<node>,greater<node> > pq1; 
priority_queue<node,vector<node>,less<node> > pq2;
vector<bool> v(1000005,0);
int pos = 0;
void pop_big(){
	while(v[pq2.top().p]) pq2.pop();
	v[pq2.top().p] = 1;
	pq2.pop();
}
void pop_small(){
	while(v[pq1.top().p]) pq1.pop();
	v[pq1.top().p] = 1;
	pq1.pop();
}
void push(int s){
	pq1.push((node){s,pos});
	pq2.push((node){s,pos++});
}
int big(){
	while(v[pq2.top().p]) pq2.pop();
	return pq2.top().n;
}
int small(){
	while(v[pq1.top().p]) pq1.pop();
	return pq1.top().n;
}