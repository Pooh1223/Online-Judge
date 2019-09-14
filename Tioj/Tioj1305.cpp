#include <cstdio>
#include <cstdlib>
using namespace std;
char order[10];
struct treap{
	int val;
	int pri;
	int sz;
	treap* l;
	treap* r;
	treap(){val = 0;pri = rand();sz = 1;l = r = NULL;}
	void pull(int x){val = x;}
	void size(){sz = 1 + ss(l ? l -> sz : 0) + ss(r ? r -> sz : 0);}
} *root;
//int ss(treap* a){return a ? a -> sz : 0;}
void merge(treap* a,treap* b){
	if(!a) return b;
	if(!b) return a;
	if(a -> pri < b -> pri){
		a -> r = merge(a -> r,b);
		a -> size();
		return a;
	} else {
		b -> l = merge(a,b -> l);
		b -> size();
		return b;
	}
}

void split(){

}

int main(){
	int num;
	while(1){
		scanf("%s",order);
		scanf("%d",num);
		if(order[0] = 'e') break;
		else if(order[0] = 'i'){
			//merge();
		}
		else if(order[0] = 'a'){

		}
		else{
			split();
		}
	}
	return 0;
}
