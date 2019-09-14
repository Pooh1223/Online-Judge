#include <iostream>
using namespace std;

long long time(long long array[],long long len,long long loop){
	long long times = 0;
	for(long long i = 1,j = 1;j < len;i++,j++){
		if(array[i - 1] > array[i])
			times++;
	}
	return (times * loop + array[len - 1]);
}

int main(){
	long long n;
	cin >> n;
	long long sidewalk[n + 1];
	sidewalk[0] = 0;
	for(long long i = 1,k = 0;i <= n;i++){
		cin >> k;
		sidewalk[k] = i;
	}
	long long st,end;
	cin >> st >> end;
	long long q = 0;
	long long cwise[n],ccwise[n];
	for(long long i = st - 1,j = 0;;i--,j++){
		if(i == 0) i = n;
		cwise[j] = sidewalk[i];
		q++;
		if(i == end) break;
	}
	for(long long i = st,j = 0;;i++,j++){
		if(i == n + 1) i = 1;
		ccwise[j] = sidewalk[i];
		if(i == end) break;
	}
	cout << min(time(cwise,q,n),time(ccwise,(n - q),n)) << endl;
	return 0;
} 
