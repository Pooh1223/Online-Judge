#include <bits/stdc++.h>
using namespace std;
long long num[100005];
struct node{
	long long lmax,rmax,midmax,sum;
	int l,r;
	int lson,rson;
}st[400005];
int stid = 1;
void build(int l,int r,int id){
	st[id].l = l,st[id].r = r;
	if(l == r){
		if(num[l] >= 0) st[id].sum = st[id].lmax = st[id].rmax = st[id].midmax = num[l];
		else {
			st[id].sum = num[l];
			st[id].lmax = st[id].rmax = st[id].midmax = 0;
		}
	} else {
		int m = (l + r) / 2;
		int lson = st[id].lson = stid++;
		int rson = st[id].rson = stid++;
		build(l,m,lson);
		build(m + 1,r,rson);
		st[id].lmax = max(st[lson].lmax,st[lson].sum + st[rson].lmax);
		st[id].rmax = max(st[rson].rmax,st[rson].sum + st[lson].rmax);
		st[id].midmax = max(max(st[lson].midmax,st[rson].midmax),st[lson].rmax + st[rson].lmax);
		st[id].sum = st[lson].sum + st[rson].sum;
	}
}
long long query(int l,int r,int id,int ql,int qr){
	if(l > qr || r < ql) return -1;
	else if(ql <= l && qr >= r) return st[id].midmax;
	else {
		int m = (l + r) / 2;
		int lson = st[id].lson;
		int rson = st[id].rson;
		//cout << st[lson].rmax << " " << st[rson].lmax << "\n";
		////////
		return max(max(query(l,m,lson,ql,qr),query(m + 1,r,rson,ql,qr)),st[lson].rmax + st[rson].lmax);
		////////
	}
}
int main(){
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;++i) cin >> num[i];
	build(1,n,0);
	/*for(int i = 0;i < stid;++i){
		printf("id : %d\nrange : %d ~ %d\nlson : %d , rson : %d\nlmax : %lld\nrmax : %lld\nmidmax : %lld\nsum : %lld\n\n"
			,i,st[i].l,st[i].r,st[i].lson,st[i].rson,st[i].lmax,st[i].rmax,st[i].midmax,st[i].sum);
	}*/
	while(q--){
		int l,r;
		cin >> l >> r;
		long long ans = query(1,n,0,l,r);
		if(ans > 0) cout << ans << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}