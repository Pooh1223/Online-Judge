#include <cstdio>

int main(){
	int n;
	scanf("%d",&n);
	int mx = -1;
	while(n--){
		int j;
		scanf("%d",&j);
		if(mx < j) mx = j;
	}
	if(mx < 25) printf("0\n");
	else printf("%d\n",mx - 25);
	return 0;
}
//Description: ... 25 people to attend the contest
//some people will quit , find the minimum number(id) of the person
//solution: if number > 25 than the answer is max - 25
//else the answer is 0