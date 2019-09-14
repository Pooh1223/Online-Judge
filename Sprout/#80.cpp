#include <iostream>
using namespace std;
const int jizz = 1e6 + 2;
int num[jizz],t,n;
struct node{
	int l,r;
	int lson,rson;
	int data;
}st[jizz * 2];
int stid = 1;
void build(int l,int r,int id){
	st[id].l = l,st[id].r = r;
	if(r - l == 1){
		st[id].data = num[l];
	} else {
		int lson = st[id].lson = stid++;
		int rson = st[id].rson = stid++;
		build(l,(l + r) / 2,lson);
		build((l + r) / 2,r,rson);
		st[id].data = min(st[lson].data,st[rson].data);
	}
}
void modify(int pos,int val,int id){
	if(st[id].r - st[id].l == 1){
		st[id].data = val;
	} else {
		int m = (st[id].l + st[id].r) / 2;
		int lson = st[id].lson;
		int rson = st[id].rson;
		if(pos < m) modify(pos,val,lson);
		else modify(pos,val,rson);
		st[id].data = min(st[lson].data,st[rson].data);
	}
}
int query(int l,int r,int id){
	if(st[id].l == l && st[id].r == r){
		return st[id].data;
	} else {
		int m = (st[id].l + st[id].r) / 2;
		int lson = st[id].lson;
		int rson = st[id].rson;
		if(r <= m) return query(l,r,lson);
		else if(l >= m) return query(l,r,rson);
		else return min(query(l,m,lson),query(m,r,rson));
	}
}
int main(){
	cin.tie(0);
	cin >> t >> n;
	for(int i = 0;i < n;++i) cin >> num[i];
	build(0,n,0);
	while(t--){
		int type,x,y;
		cin >> type >> x >> y;
		if(type == 1) cout << query(x,y,0) << '\n';
		else modify(x,y,0);
	}
	return 0;
}