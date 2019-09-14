#include <bits/stdc++.h>
using namespace std;
bool used[10];
int main(){
	srand(time(NULL));
	for(int i = 0;i < 10;++i){
		int jizz = rand() % 10;
		while(used[jizz]) jizz = rand() % 10;
		used[jizz] = 1;
		cout << jizz << " ";
	}
	return 0;
}