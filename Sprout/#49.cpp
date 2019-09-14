#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct tree{
	int data;
	vector<tree*> child;
	tree(){data = 0;child.clear();}
};

tree* v[100005];
int ans[100005];
void init(){
	for(int i = 0;i < 100005;i++){
		v[i] = new tree();
		v[i] -> data = i;
	}
}

void init2(int n){
	for(int i = 0;i <= n;i++){
		v[i] -> child.clear();
	}
}

int query(tree* temp){
	int size = 1;
	for(int i = 0;i < temp -> child.size();i++){
		size += query(temp -> child[i]);
	}
	ans[temp -> data] = size;
	return size;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	init();
	while(t--){
		int id,n;
		cin >> id >> n;
		while(n--){
			int a,b;
			cin >> a >> b;
			v[a] -> child.push_back(v[b]);
		}
		int q;
		cin >> q;
		while(q--){
			int x;
			cin >> x;
			if(!ans[x]) cout << query(v[x]) << "\n";
			else cout << ans[x] << "\n";
		}
		init2(id);
		memset(ans,0,sizeof(ans));
	}
	return 0;
}