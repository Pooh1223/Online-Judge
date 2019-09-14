#include <bits/stdc++.h>
using namespace std;
#define jizz 100005
#define ll long long
ll num[jizz];
struct node{
	int ad,ch;
	int mx;
	int l,r;
	int lson,rson;
}st[jizz * 4];
int stid = 1;
void build(int l,int r,int id){
	st[id].l = l,st[id].r = r;
	if(l == r){
		st[id].mx = num[l];
		st[id].ad = st[id].ch = 0;
	} else {
		int m = (l + r) / 2;
		int lson = st[id].lson = stid++;
		int rson = st[id].rson = stid++;
		build(l,m,lson);
		build(m + 1,r,rson);
		st[id].mx = max(st[lson].mx,st[rson].mx);
	}
}
void push(int id,int lson,int rson){
	if(st[id].ch > 0){
		st[id].mx = st[id].ch;
		if(lson >= 0) st[lson].ch = st[id].ch,st[lson].ad = 0;
		if(rson >= 0) st[rson].ch = st[id].ch,st[rson].ad = 0;
		st[id].ch = 0;
	}
	if(st[id].ad > 0){
		st[id].mx += st[id].ad;
		if(lson >= 0) st[lson].ad += st[id].ad;
		if(rson >= 0) st[rson].ad += st[id].ad;
		st[id].ad = 0;
	}
}
void add(int l,int r,int id,int ql,int qr,int val){
	int lson = st[id].lson,rson = st[id].rson;
	if(l == r) lson = rson = -1;
	push(id,lson,rson);
	if(r < ql || l > qr) return;
	else if(ql <= l && r <= qr) st[id].ad += val;
	else {
		int m = (l + r) / 2;
		add(l,m,lson,ql,qr,val);
		add(m + 1,r,rson,ql,qr,val);
		int lll = (st[lson].ch > 0 ? st[lson].ch : st[lson].mx) + st[lson].ad;
		int rr = (st[rson].ch > 0 ? st[rson].ch : st[rson].mx) + st[rson].ad;
		st[id].mx = max(lll,rr);
	}
}
void change(int l,int r,int id,int ql,int qr,int val){
	int lson = st[id].lson,rson = st[id].rson;
	if(l == r) lson = rson = -1;
	push(id,lson,rson);
	if(l > qr || r < ql) return;
	else if(ql <= l && r <= qr) st[id].ch = val;
	else {
		int m = (l + r) / 2;
		change(l,m,lson,ql,qr,val);
		change(m + 1,r,rson,ql,qr,val);
		int lll = (st[lson].ch > 0 ? st[lson].ch : st[lson].mx) + st[lson].ad;
		int rr = (st[rson].ch > 0 ? st[rson].ch : st[rson].mx) + st[rson].ad;
		st[id].mx = max(lll,rr);
	}
}
int query(int l,int r,int id,int ql,int qr){
	int lson = st[id].lson,rson = st[id].rson;
	if(l == r) lson = rson = -1;
	push(id,lson,rson);
	if(l > qr || r < ql) return -1;
	else if(ql <= l && r <= qr) return st[id].mx;
	else {
		int m = (l + r) / 2;
		return max(query(l,m,lson,ql,qr),query(m + 1,r,rson,ql,qr)) + st[id].ad;
	}
}
int main(){
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;++i) cin >> num[i];
	build(1,n,0);
	while(q--){
		int t,l,r,x;
		cin >> t >> l >> r;
		if(t == 1){
			cin >> x;
			add(1,n,0,l,r,x);
		} else if(t == 2){
			cout << query(1,n,0,l,r) << "\n";
		} else {
			cin >> x;
			change(1,n,0,l,r,x);
		}
	}
	return 0;
}