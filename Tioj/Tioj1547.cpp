#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int f[30] = {1,2,3,5,8,13,21,34,55,89,
	144,233,377,610,987,1597,2584,4181,6765,10946,
	17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269};
	for(int i = 0,j = 1;i < n;i++){
		for(int k = 0;k < f[i];j++,k++){
			cout << j % 3;
		}
		cout << endl;
	}
	return 0;
} 
