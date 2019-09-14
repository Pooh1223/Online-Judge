#include <iostream>
using namespace std;

int main(){
	char time1[10],time2[10];
	for(int i = 0;i < 8;i++) cin >> time1[i];
	for(int i = 0;i < 8;i++) cin >> time2[i];
	int sum1 = (((time1[0] - '0') * 10 + (time1[1] - '0')) * 3600 
		+ ((time1[3] - '0') * 10 + (time1[4] - '0')) * 60 
		+ (time1[6] - '0') * 10 + (time1[7] - '0'));
	int sum2 = (((time2[0] - '0') * 10 + (time2[1] - '0')) * 3600 
		+ ((time2[3] - '0') * 10 + (time2[4] - '0')) * 60 
		+ (time2[6] - '0') * 10 + (time2[7] - '0'));
	if(sum1 > sum2) sum2 += 86400;
	sum1 = sum2 - sum1;
	int h = sum1 / 3600;
	sum1 -= (h * 3600);
	int m = sum1 / 60;
	sum1 -= (m * 60);
	if(h < 10) cout << "0" << h << ":";
	else cout << h << ":";
	if(m < 10) cout << "0" << m << ":";
	else cout << m << ":";
	if(sum1 < 10) cout << "0" << sum1 << endl;
	else cout << sum1;
	return 0;
}
