#include <bits/stdc++.h>
using namespace std;



int main(){
	
	int t;
	scanf("%d",&t);

	while(t--){
		double a,b,ans;
		scanf("%lf %lf",&a,&b);
		ans = (b - a) * 100.0 / a ;
		
		double basis = -0.005,k = 0;

		if(ans > basis && ans < k) printf("   0.00%% ");
		else if(ans < 0) printf("%7.2f%% ",(int)(ans * 100.0 - 0.5) / 100.0);
		else printf("%7.2f%% ",(int)(ans * 100.0 + 0.5) / 100.0);

		double jizz = 4.995;

		if(ans >= jizz){
			printf("(#`Д´)ﾉ\n");
		} else if(ans <= -jizz){
			printf("(ゝ∀･)b\n");
		} else {
			printf("\\^o^/\n");
		}
	}
	return 0;
}