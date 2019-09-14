#include <cstdio>
#include <cstring>
using namespace std;

char p[1005],q[1005];
int len1,len2;

int ck(int len){
	for(int i = 0;i < len;i++){
		if(p[i] != q[len2 - len + i]) return 0;
	}
	return 1;
}

int main(){
	scanf("%s%s",p,q);
	len1 = strlen(p);
	len2 = strlen(q);
	int ans = 0;
	for(int i = 0;i <= len1 && i <= len2;i++){
		if(ck(i)) ans = i;
	}
	printf("%d\n",ans);
	return 0;
}
