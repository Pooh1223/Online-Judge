#include <iostream>
using namespace std;
const int jizz = 1e5 + 2;
long long num[jizz];
struct node{
	int l,r;
	int lson,rson;
	int val,data;
}st[2 * jizz];
int stid = 1;
void build(int l,int r,int id){
	st[id].l = l,st[id].r = r;
	if(l == r){
		st[id].data = num[l];
		st[id].val = 0;
	} else {
		int m = (l + r) / 2;
		int lson = st[id].lson = stid++;
		int rson = st[id].rson = stid++;
		build(l,m,lson);
		build(m + 1,r,rson);
		st[id].data = max(st[lson].data,st[rson].data);
	}
}
void add(int a,int b,int id,int l,int r,int x){
	if(b < l || a > r) return;
	else if(a <= l && b >= r) st[id].val += x;
	else {
		int m = (l + r) / 2;
		int lson = st[id].lson;
		int rson = st[id].rson;
		add(a,b,lson,l,m,x);
		add(a,b,rson,m + 1,r,x);
		st[id].data = max(st[lson].data + st[lson].val,st[rson].data + st[rson].val);
	}
}
int query(int a,int b,int id,int l,int r){
	if(b < l || a > r) return -1;
	else if(a <= l && b >= r) return st[id].data + st[id].val;
	else {
		int m = (l + r) / 2;
		int lson = st[id].lson;
		int rson = st[id].rson;
		return max(query(a,b,lson,l,m),query(a,b,rson,m + 1,r)) + st[id].val;
	}
}
int main(){
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;++i) cin >> num[i];
	build(1,n,0);
	while(q--){
		int type,l,r,x;
		cin >> type >> l >> r;
		if(type == 1){
			cin >> x;
			add(l,r,0,1,n,x);
		} else {
			cout << query(l,r,0,1,n) << '\n';
		}
	}
	return 0;
}