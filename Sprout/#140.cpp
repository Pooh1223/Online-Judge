#include <bits/stdc++.h>
using namespace std;
#define jizz 1000007
int num[3][100005][3];
int main(){
	int t;
	scanf("%d",&t);
	num[0][2][0] = 1; num[0][2][1] = 1; num[0][2][2] = 1;
	num[1][2][0] = 1; num[1][2][1] = 1; num[1][2][2] = 1;
	num[2][2][0] = 1; num[2][2][1] = 1; num[2][2][2] = 1;
	num[0][3][0] = 3; num[0][3][1] = 2; num[0][3][2] = 2;
	num[1][3][0] = 2; num[1][3][1] = 2; num[1][3][2] = 1;
	num[2][3][0] = 2; num[2][3][1] = 1; num[2][3][2] = 2;
	num[0][4][0] = 7; num[0][4][1] = 5; num[0][4][2] = 5;
	num[1][4][0] = 5; num[1][4][1] = 4; num[1][4][2] = 3;
	num[2][4][0] = 5; num[2][4][1] = 3; num[2][4][2] = 4;
	for(int i = 5;i <= 100000;++i){
		num[0][i][0] = (num[0][i - 2][0] + num[0][i - 2][1] + num[0][i - 2][2]
					 + num[1][i - 2][0] + num[1][i - 2][1] + num[1][i - 2][2]
					 + num[2][i - 2][0] + num[2][i - 2][1] + num[2][i - 2][2]) % jizz;
		num[0][i][1] = (num[0][i - 2][0] + num[0][i - 2][1] + num[1][i - 2][0]
					 + num[1][i - 2][1] + num[2][i - 2][0] + num[2][i - 2][1]) % jizz;
		num[0][i][2] = (num[0][i - 2][0] + num[0][i - 2][2] + num[1][i - 2][0]
					 + num[1][i - 2][2] + num[2][i - 2][0] + num[2][i - 2][2]) % jizz;
		num[1][i][0] = (num[0][i - 2][0] + num[0][i - 2][1] + num[0][i - 2][2]
				 	 + num[1][i - 2][0] + num[1][i - 2][1] + num[1][i - 2][2]) % jizz;
		num[1][i][1] = (num[0][i - 2][0] + num[0][i - 2][1] + num[1][i - 2][0]
					 + num[1][i - 2][1]) % jizz;
		num[1][i][2] = (num[0][i - 2][0] + num[0][i - 2][2] + num[1][i - 2][0]
					 + num[1][i - 2][2]) % jizz;
		num[2][i][0] = (num[0][i - 2][0] + num[0][i - 2][1] + num[0][i - 2][2]
					 + num[2][i - 2][0] + num[2][i - 2][1] + num[2][i - 2][2]) % jizz;
		num[2][i][1] = (num[0][i - 2][0] + num[0][i - 2][1] + num[2][i - 2][0]
					 + num[2][i - 2][1]) % jizz;
		num[2][i][2] = (num[0][i - 2][0] + num[0][i - 2][2] + num[2][i - 2][0]
					 + num[2][i - 2][2]) % jizz;
	}
	while(t--){
		int n;
		scanf("%d",&n);
		if(n == 1) printf("3\n");
		else printf("%d\n",(num[0][n][0] + num[0][n][1] + num[0][n][2] + num[1][n][0] + num[1][n][1] + num[2][n][0] + num[2][n][2]) % jizz);
	}

	return 0;
}